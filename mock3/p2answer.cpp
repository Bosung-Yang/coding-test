#include <string>
#include <vector>

using namespace std;

// 로트별 집계 정보
struct Lot {
    string id;
    int best;    // 최고 점수
    int count;   // 검사 횟수
};

// a가 b보다 순위가 앞이면 true
bool isAhead(const Lot& a, const Lot& b) {
    if (a.best != b.best) return a.best > b.best;      // 1. 최고 점수 높은 순
    if (a.count != b.count) return a.count < b.count;  // 2. 검사 횟수 적은 순
    return a.id < b.id;                                // 3. 로트ID 사전순
}

vector<string> solution(vector<string> logs, int k) {
    vector<Lot> lots;

    // 1. 로그 파싱 + 로트별 집계 (map 대신 선형 탐색)
    for (const string& log : logs) {
        int space = log.find(' ');
        string id = log.substr(0, space);
        int score = stoi(log.substr(space + 1));

        int found = -1;
        for (int i = 0; i < (int)lots.size(); i++) {
            if (lots[i].id == id) { found = i; break; }
        }

        if (found == -1) {
            lots.push_back({id, score, 1});            // 처음 보는 로트
        } else {
            lots[found].count++;                       // 기존 로트 갱신
            if (score > lots[found].best) lots[found].best = score;
        }
    }

    // 2. 삽입 정렬 (sort 대신 직접 구현, 로트 수 ≤ 1000 이라 O(n²)도 충분)
    for (int i = 1; i < (int)lots.size(); i++) {
        Lot cur = lots[i];
        int j = i - 1;
        while (j >= 0 && isAhead(cur, lots[j])) {      // cur가 앞이면 한 칸씩 밀기
            lots[j + 1] = lots[j];
            j--;
        }
        lots[j + 1] = cur;
    }

    // 3. 상위 k개 (로트가 k개보다 적으면 전부)
    vector<string> answer;
    for (int i = 0; i < (int)lots.size() && i < k; i++) {
        answer.push_back(lots[i].id);
    }
    return answer;
}
