// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> scores, int limit, int K);
int main() {
    int n, m, limit, K; cin >> n >> m >> limit >> K; vector<vector<int>> s(n, vector<int>(m));
    for (auto& r : s) for (int& x : r) cin >> x;
    cout << solution(s, limit, K) << '\n';
}
