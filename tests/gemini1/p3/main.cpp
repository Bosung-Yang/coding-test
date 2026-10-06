// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<vector<int>> jobs);
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n; vector<vector<int>> j(n, vector<int>(3)); for (auto& r : j) cin >> r[0] >> r[1] >> r[2];
    auto a = solution(j);
    for (size_t i = 0; i < a.size(); i++) cout << a[i] << (i + 1 < a.size() ? " " : "");
    cout << '\n';
}
