// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> synergy);
int main() {
    int n; cin >> n; vector<vector<int>> s(n, vector<int>(n));
    for (auto& r : s) for (int& x : r) cin >> x;
    cout << solution(s) << '\n';
}
