#include <string>
#include <vector>

using namespace std;

// N×M 배열을 시계 방향 90도 회전 → M×N
// 원래 (i, j) → 회전 후 (j, N-1-i)
//   원래 맨 윗줄(i = 0)이 회전 후 맨 오른쪽 열(N-1)이 됨
vector<vector<int>> rotate90(const vector<vector<int>>& a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> r(m, vector<int>(n));   // 크기가 뒤바뀜
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            r[j][n - 1 - i] = a[i][j];
        }
    }
    return r;
}

vector<vector<int>> solution(vector<vector<int>> a, int k) {
    // 4번 회전하면 원래대로 → k % 4번만 회전 (k는 최대 10억)
    for (int t = 0; t < k % 4; t++) {
        a = rotate90(a);
    }
    return a;
}
