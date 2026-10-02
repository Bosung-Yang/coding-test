// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> times, int m, vector<vector<int>> conflicts);
int main() {
    int n, m, c; cin >> n >> m; vector<int> t(n); for (int& x : t) cin >> x;
    cin >> c; vector<vector<int>> cf(c, vector<int>(2)); for (auto& p : cf) cin >> p[0] >> p[1];
    cout << solution(t, m, cf) << '\n';
}
