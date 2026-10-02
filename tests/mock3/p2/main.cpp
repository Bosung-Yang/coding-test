// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
vector<string> solution(vector<string> logs, int k);
int main() {
    int n, k; cin >> n >> k; string line; getline(cin, line);
    vector<string> logs(n); for (auto& s : logs) getline(cin, s);
    for (auto& s : solution(logs, k)) cout << s << '\n';
}
