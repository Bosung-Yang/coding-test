// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
int solution(vector<string> grid);
int main() {
    int r, c; cin >> r >> c; vector<string> g(r); for (auto& s : g) cin >> s;
    cout << solution(g) << '\n';
}
