#include <string>
#include <vector>

using namespace std;

string solution(vector<string> commands) {
    string answer = "";
    vector<long long> st;

    for (string cmd : commands){
        if (cmd.substr(0,3) == "PUS"){
            long long x = stoll(cmd.substr(4));
            st.push_back(x);
        }
        if (cmd == "POP"){
            if (st.size() < 1) return "ERROR";
            st.pop_back();
        }
        if (cmd =="DUP"){
            if (st.size() < 1) return "ERROR";
            long long x = st.back();
            st.push_back(x);
        }
        if (cmd =="SWAP"){
            if (st.size() < 2) return "ERROR";
            long long x = st.back(); st.pop_back();
            long long y = st.back(); st.pop_back();
            st.push_back(x);
            st.push_back(y);
        }
        if (cmd =="ADD"){
            if (st.size() < 2) return "ERROR";
            long long x = st.back(); st.pop_back();
            long long y = st.back(); st.pop_back();
            if (x+y > 1000000000) return "ERROR";
            st.push_back(x+y);
        }
        if (cmd =="SUB"){
            if (st.size() < 2) return "ERROR";
            long long x = st.back(); st.pop_back();
            long long y = st.back(); st.pop_back();
            if (y-x <  -1000000000) return "ERROR";
            st.push_back(y-x);
        }
        if (cmd =="MUL"){
            if (st.size() < 2) return "ERROR";
            long long x = st.back(); st.pop_back();
            long long y = st.back(); st.pop_back();
            if (x*y <  -1000000000 || x*y > 1000000000) return "ERROR";
            st.push_back(x*y);
        }
    }
    if (st.empty()) return "EMPTY";
    else return to_string(st.back());
    return answer;
}
