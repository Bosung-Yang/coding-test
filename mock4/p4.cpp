#include <string>
#include <vector>

using namespace std;

int n, need, best;
vector<int> C, P;
vector<vector<bool>> conflict;   // conflict[a][b] : a와 b는 함께 설치 불가
vector<bool> picked;             // 설치하기로 고른 장비

// 고르기 백트래킹 : 고른 순서는 상관없으므로 start번 이후 장비만 후보
// cost : 지금까지 비용, power : 지금까지 전력
void dfs(int start, int cost, int power) {
    if (cost >= best) return;                    // 가지치기 (비용은 줄지 않음)
    if (power >= need) { best = cost; return; }  // 전력 충족 → 더 고르면 비용만 늘어남

    for (int i = start; i < n; i++) {
        // 이미 고른 장비와 간섭하면 불가
        bool ok = true;
        for (int j = 0; j < i; j++) {
            if (picked[j] && conflict[i][j]) { ok = false; break; }
        }
        if (!ok) continue;

        picked[i] = true;
        dfs(i + 1, cost + C[i], power + P[i]);   // 다음은 i 뒤에서부터
        picked[i] = false;                       // 되돌리기
    }
}

int solution(vector<int> cost, vector<int> power, int needPower, vector<vector<int>> conflicts) {
    n = cost.size();
    C = cost;
    P = power;
    need = needPower;
    conflict.assign(n, vector<bool>(n, false));
    for (const vector<int>& c : conflicts) {
        conflict[c[0]][c[1]] = true;
        conflict[c[1]][c[0]] = true;
    }
    picked.assign(n, false);
    best = 1e9;

    dfs(0, 0, 0);
    return best == 1e9 ? -1 : best;
}
