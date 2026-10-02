// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> cost, vector<int> power, int needPower, vector<vector<int>> conflicts);
int main() {
    int n, need, m; cin >> n >> need; vector<int> c(n), p(n);
    for (int& x : c) cin >> x; for (int& x : p) cin >> x;
    cin >> m; vector<vector<int>> cf(m, vector<int>(2)); for (auto& q : cf) cin >> q[0] >> q[1];
    cout << solution(c, p, need, cf) << '\n';
}
