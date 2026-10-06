#include <string>
#include <vector>

using namespace std;

int N, K, best;
vector<vector<int>> V;
vector<vector<bool>> placed;   // 검사원을 배치한 칸

// 고르기 백트래킹 : 칸에 0 ~ N*N-1 번호를 매기고, start번 칸 이후만 후보로
// (start 이후만 보면 같은 칸 중복 배치와 순서만 다른 중복이 모두 사라짐)
void dfs(int start, int cnt, int sum) {
    if (cnt == K) {
        if (sum > best) best = sum;
        return;
    }
    for (int c = start; c < N * N; c++) {
        int y = c / N, x = c % N;            // 번호 → 좌표
        if (V[y][x] == 0) continue;          // 장비가 있는 칸

        // 앞 번호 칸만 배치되어 있으므로 위쪽, 왼쪽 이웃만 확인하면 충분
        if (y > 0 && placed[y - 1][x]) continue;
        if (x > 0 && placed[y][x - 1]) continue;

        placed[y][x] = true;
        dfs(c + 1, cnt + 1, sum + V[y][x]);
        placed[y][x] = false;                // 되돌리기
    }
}

int solution(vector<vector<int>> grid, int k) {
    V = grid;
    N = grid.size();
    K = k;
    best = -1;                               // 끝까지 못 고르면 -1 그대로
    placed.assign(N, vector<bool>(N, false));

    dfs(0, 0, 0);
    return best;
}
