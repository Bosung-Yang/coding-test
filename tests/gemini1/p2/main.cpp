// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> process, int C);
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, C; cin >> n >> C; vector<int> p(n); for (int& x : p) cin >> x;
    cout << solution(p, C) << '\n';
}
