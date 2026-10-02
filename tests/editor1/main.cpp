// 채점용 main (수정 X). 풀이 파일에는 solution 함수만 작성
#include <bits/stdc++.h>
using namespace std;
string solution(string init, vector<string> commands);
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string init, line; getline(cin, init);
    int n; cin >> n; getline(cin, line);
    vector<string> cmds(n);
    for (auto& c : cmds) getline(cin, c);
    cout << solution(init, cmds) << '\n';
}
