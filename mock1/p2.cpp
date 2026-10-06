#include <string>
#include <vector>

using namespace std;

int n;
int best;                       // 지금까지 찾은 최소 비용 (-1 = 아직 없음)
vector<vector<int>> c;          // 전환 비용
vector<vector<int>> pre;        // pre[b] : b보다 먼저 와야 하는 공정 목록
vector<bool> used;

// 순서 정하기 백트래킹
// cnt : 지금까지 배치한 공정 수, last : 마지막 공정(-1 = 아직 없음), sum : 현재 비용
void dfs(int cnt, int last, int sum) {
    if (best != -1 && sum >= best) return;          // 가지치기 (비용은 줄지 않음)
    if (cnt == n) { best = sum; return; }

    for (int next = 0; next < n; next++) {
        if (used[next]) continue;

        // next보다 먼저 와야 하는 공정이 모두 끝났는지 확인
        bool ok = true;
        for (int p : pre[next]) {
            if (!used[p]) { ok = false; break; }
        }
        if (!ok) continue;

        int add = (last == -1) ? 0 : c[last][next];  // 첫 공정은 비용 0
        used[next] = true;
        dfs(cnt + 1, next, sum + add);
        used[next] = false;                          // 되돌리기
    }
}

int solution(vector<vector<int>> cost, vector<vector<int>> order) {
    n = cost.size();
    c = cost;
    pre.assign(n, vector<int>());
    for (const vector<int>& o : order) pre[o[1]].push_back(o[0]);   // o[0]이 o[1]보다 먼저
    used.assign(n, false);
    best = -1;

    dfs(0, -1, 0);

    // 완성된 순서가 하나도 없으면(선후 관계에 사이클) best는 -1 그대로
    return best;
}
