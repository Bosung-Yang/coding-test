// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> temp, int k);
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k; vector<vector<int>> t(n, vector<int>(m));
    for (auto& r : t) for (int& x : r) cin >> x;
    cout << solution(t, k) << '\n';
}
