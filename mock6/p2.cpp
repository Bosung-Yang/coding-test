#include <string>
#include <vector>

using namespace std;

const long long LIMIT = 1000000000;

string solution(vector<string> commands) {
    vector<long long> st;   // 스택 (곱셈 결과가 int를 넘을 수 있으므로 long long)

    for (const string& cmd : commands) {
        if (cmd.substr(0, 4) == "PUSH") {
            st.push_back(stoll(cmd.substr(5)));       // 음수도 stoll로 처리됨
        }
        else if (cmd == "POP") {
            if (st.empty()) return "ERROR";
            st.pop_back();
        }
        else if (cmd == "DUP") {
            if (st.empty()) return "ERROR";
            st.push_back(st.back());
        }
        else {   // SWAP, ADD, SUB, MUL : 값 2개 필요
            if (st.size() < 2) return "ERROR";
            long long a = st.back(); st.pop_back();   // 맨 위
            long long b = st.back(); st.pop_back();   // 그 아래

            if (cmd == "SWAP") {
                st.push_back(a);
                st.push_back(b);
                continue;
            }

            long long v;
            if (cmd == "ADD") v = b + a;
            else if (cmd == "SUB") v = b - a;          // 아래 - 위
            else v = b * a;                            // 최대 10^18 → long long 범위 안

            if (v > LIMIT || v < -LIMIT) return "ERROR";
            st.push_back(v);
        }
    }

    if (st.empty()) return "EMPTY";
    return to_string(st.back());
}
