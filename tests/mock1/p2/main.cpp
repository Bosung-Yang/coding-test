// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> cost, vector<vector<int>> order);
int main() {
    int n; cin >> n; vector<vector<int>> cost(n, vector<int>(n));
    for (auto& r : cost) for (int& x : r) cin >> x;
    int m; cin >> m; vector<vector<int>> order(m, vector<int>(2));
    for (auto& o : order) cin >> o[0] >> o[1];
    cout << solution(cost, order) << '\n';
}
