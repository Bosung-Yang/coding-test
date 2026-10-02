// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> readings, int t);
int main() {
    int n, t; cin >> n >> t; vector<int> r(n); for (int& x : r) cin >> x;
    auto a = solution(r, t);
    for (size_t i = 0; i < a.size(); i++) cout << a[i] << (i + 1 < a.size() ? " " : "");
    cout << '\n';
}
