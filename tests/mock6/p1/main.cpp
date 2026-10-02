// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
int solution(vector<string> grid, vector<string> pattern);
int main() {
    int n, m; cin >> n; vector<string> g(n); for (auto& s : g) cin >> s;
    cin >> m; vector<string> p(m); for (auto& s : p) cin >> s;
    cout << solution(g, p) << '\n';
}
