// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
string solution(vector<string> commands);
int main() {
    int n; cin >> n; string line; getline(cin, line);
    vector<string> c(n); for (auto& s : c) getline(cin, s);
    cout << solution(c) << '\n';
}
