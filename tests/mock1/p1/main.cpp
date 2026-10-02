// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
vector<string> solution(vector<string> logs);
int main() {
    int n; cin >> n; string line; getline(cin, line);
    vector<string> logs(n); for (auto& s : logs) getline(cin, s);
    for (auto& s : solution(logs)) cout << s << '\n';
}
