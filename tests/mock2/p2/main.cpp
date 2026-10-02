// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(int n, vector<string> commands);
int main() {
    int n, q; cin >> n >> q; string line; getline(cin, line);
    vector<string> c(q); for (auto& s : c) getline(cin, s);
    auto r = solution(n, c);
    for (size_t i = 0; i < r.size(); i++) cout << r[i] << (i + 1 < r.size() ? " " : "");
    cout << '\n';
}
