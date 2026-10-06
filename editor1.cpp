#include <string>
#include <vector>

using namespace std;

// 커서를 기준으로 문자열을 스택 두 개로 나눠서 관리
//   left  : 커서 왼쪽 문자들 (맨 뒤 = 커서 바로 왼쪽)
//   right : 커서 오른쪽 문자들 (맨 뒤 = 커서 바로 오른쪽)
// → L, R, P, B 모두 O(1)
//
// 되돌리기 : 실제로 동작한 명령(L, R, P, B)을 history에 쌓아 두고,
//            U가 오면 편집(P 또는 B)을 하나 만날 때까지 거꾸로 되돌림
//            (편집 뒤에 한 커서 이동까지 되감아야 커서가 편집 직전 위치로 돌아감)
// 각 기록은 한 번 쌓이고 한 번만 꺼내지므로 전체 O(명령 수)

struct Record {
    char type;   // 'L', 'R', 'P', 'B'
    char ch;     // B로 지운 문자 (되돌릴 때 다시 넣기 위해)
};

string solution(string init, vector<string> commands) {
    vector<char> left(init.begin(), init.end());
    vector<char> right;
    vector<Record> history;
    int edits = 0;   // history 안에 남아 있는 편집(P, B) 개수

    for (const string& cmd : commands) {
        char type = cmd[0];

        if (type == 'L') {
            if (left.empty()) continue;          // 무시된 명령은 기록하지 않음
            right.push_back(left.back());
            left.pop_back();
            history.push_back({'L', 0});
        }
        else if (type == 'R') {
            if (right.empty()) continue;
            left.push_back(right.back());
            right.pop_back();
            history.push_back({'R', 0});
        }
        else if (type == 'P') {
            left.push_back(cmd[2]);              // "P x" 에서 x는 인덱스 2
            history.push_back({'P', 0});
            edits++;
        }
        else if (type == 'B') {
            if (left.empty()) continue;
            history.push_back({'B', left.back()});
            left.pop_back();
            edits++;
        }
        else {   // 'U'
            if (edits == 0) continue;            // 되돌릴 편집이 없으면 이동 기록도 건드리지 않음
            edits--;
            while (true) {
                Record r = history.back();
                history.pop_back();
                if (r.type == 'L') {             // 왼쪽 이동 되돌리기 → 오른쪽으로
                    left.push_back(right.back());
                    right.pop_back();
                }
                else if (r.type == 'R') {        // 오른쪽 이동 되돌리기 → 왼쪽으로
                    right.push_back(left.back());
                    left.pop_back();
                }
                else if (r.type == 'P') {        // 입력 되돌리기 → 지움
                    left.pop_back();
                    break;
                }
                else {                           // 삭제 되돌리기 → 다시 넣음
                    left.push_back(r.ch);
                    break;
                }
            }
        }
    }

    // left + (right를 뒤집은 것)
    string result(left.begin(), left.end());
    for (int i = (int)right.size() - 1; i >= 0; i--) result += right[i];
    return result;
}
