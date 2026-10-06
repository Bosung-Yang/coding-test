#include <string>
#include <vector>

using namespace std;

// 닫는 괄호에 짝이 되는 여는 괄호
char openOf(char c) {
    if (c == ')') return '(';
    if (c == ']') return '[';
    return '{';
}

int solution(string s) {
    vector<char> st;   // 아직 닫히지 않은 여는 괄호들

    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            st.push_back(c);
        } else {
            // 짝지을 여는 괄호가 없거나, 가장 최근 여는 괄호와 종류가 다르면 오류
            if (st.empty() || st.back() != openOf(c)) return i;
            st.pop_back();
        }
    }

    // 닫히지 않은 여는 괄호가 남아 있으면 문자열 길이
    if (!st.empty()) return s.size();
    return -1;
}
