// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<string> codes);
int main() {
    int n; cin >> n; vector<string> c(n); for (auto& s : c) cin >> s;
    auto a = solution(c);
    for (size_t i = 0; i < a.size(); i++) cout << a[i] << (i + 1 < a.size() ? " " : "");
    cout << '\n';
}
