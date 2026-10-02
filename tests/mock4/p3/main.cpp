// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<string> grid);
int main() {
    int r, c; cin >> r >> c; vector<string> g(r); for (auto& s : g) cin >> s;
    auto a = solution(g);
    for (size_t i = 0; i < a.size(); i++) cout << a[i] << (i + 1 < a.size() ? " " : "");
    cout << '\n';
}
