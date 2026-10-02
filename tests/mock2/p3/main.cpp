// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
int solution(vector<string> grid, int k);
int main() {
    int r, c, k; cin >> r >> c >> k; vector<string> g(r); for (auto& s : g) cin >> s;
    cout << solution(g, k) << '\n';
}
