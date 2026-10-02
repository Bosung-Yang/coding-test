// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<vector<int>> score);
int main() {
    int n, m; cin >> n >> m; vector<vector<int>> s(n, vector<int>(m));
    for (auto& r : s) for (int& x : r) cin >> x;
    auto r = solution(s);
    for (size_t i = 0; i < r.size(); i++) cout << r[i] << (i + 1 < r.size() ? " " : "\n");
}
