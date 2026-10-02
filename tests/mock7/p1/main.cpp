// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> solution(vector<vector<int>> a, int k);
int main() {
    int n, m, k; cin >> n >> m >> k; vector<vector<int>> a(n, vector<int>(m));
    for (auto& r : a) for (int& x : r) cin >> x;
    for (auto& r : solution(a, k)) { for (size_t j = 0; j < r.size(); j++) cout << r[j] << (j + 1 < r.size() ? " " : ""); cout << '\n'; }
}
