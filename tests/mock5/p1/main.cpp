// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<vector<int>> production);
int main() {
    int n, m; cin >> n >> m; vector<vector<int>> p(n, vector<int>(m));
    for (auto& r : p) for (int& x : r) cin >> x;
    auto a = solution(p);
    for (size_t i = 0; i < a.size(); i++) cout << a[i] << (i + 1 < a.size() ? " " : "");
    cout << '\n';
}
