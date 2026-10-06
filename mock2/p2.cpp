#include <string>
#include <vector>

using namespace std;

const int EMPTY = 0;   // 빈 칸 (id는 1 이상)

// s를 공백 기준으로 나눔
vector<string> split(const string& s) {
    vector<string> result;
    string cur = "";
    for (char c : s) {
        if (c == ' ') {
            if (!cur.empty()) result.push_back(cur);
            cur = "";
        } else {
            cur += c;
        }
    }
    if (!cur.empty()) result.push_back(cur);
    return result;
}

vector<int> solution(int n, vector<string> commands) {
    vector<int> mem(n, EMPTY);   // mem[i] : i번 칸을 가진 프로그램 id
    vector<int> answer;

    for (const string& cmd : commands) {
        vector<string> t = split(cmd);
        int id = stoi(t[1]);

        if (t[0] == "A") {
            int size = stoi(t[2]);

            // 연속 빈 칸 개수를 세다가 size개가 되는 순간의 시작 위치 = 가장 앞 위치
            int run = 0, start = -1;
            for (int i = 0; i < n; i++) {
                if (mem[i] == EMPTY) run++;
                else run = 0;
                if (run == size) { start = i - size + 1; break; }
            }

            // 찾았으면 실제로 메모리에 id를 기록
            if (start != -1) {
                for (int i = start; i < start + size; i++) mem[i] = id;
            }
            answer.push_back(start);   // 실패면 -1
        }
        else {   // "F"
            for (int i = 0; i < n; i++) {
                if (mem[i] == id) mem[i] = EMPTY;
            }
        }
    }
    return answer;
}
