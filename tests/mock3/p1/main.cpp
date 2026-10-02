// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<string> grid, vector<string> commands);
int main() {
    int r, c, q; cin >> r >> c; vector<string> g(r); for (auto& s : g) cin >> s;
    cin >> q; string line; getline(cin, line); vector<string> cmd(q); for (auto& s : cmd) getline(cin, s);
    auto a = solution(g, cmd);
    for (size_t i = 0; i < a.size(); i++) cout << a[i] << (i + 1 < a.size() ? " " : "");
    cout << '\n';
}
