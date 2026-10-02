// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> grid, int k);
int main() {
    int n, k; cin >> n >> k; vector<vector<int>> g(n, vector<int>(n));
    for (auto& r : g) for (int& x : r) cin >> x;
    cout << solution(g, k) << '\n';
}
