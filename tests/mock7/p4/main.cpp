// 채점용 main (수정 X)
#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> nums, vector<int> ops);
int main() {
    int n; cin >> n; vector<int> a(n), o(4); for (int& x : a) cin >> x; for (int& x : o) cin >> x;
    auto r = solution(a, o); cout << r[0] << " " << r[1] << '\n';
}
