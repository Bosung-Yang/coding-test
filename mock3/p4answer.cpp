#include <string>
#include <vector>

using namespace std;

int P;                       // 지점 수 (0번 = S, 1번~ = P)
int best;                    // 지금까지 찾은 최소 이동 횟수
vector<vector<int>> D;       // D[i][j] : i번 지점 → j번 지점 최단 거리
vector<bool> used;           // 방문한 검사 지점

// (sy, sx)에서 모든 칸까지의 최단 거리 (-1 = 도달 불가)
vector<vector<int>> bfs(const vector<string>& grid, int sy, int sx) {
    int R = grid.size(), C = grid[0].size();
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};
    vector<vector<int>> dist(R, vector<int>(C, -1));

    vector<int> qy, qx;      // <queue> 대신 vector + head 로 큐 구현
    int head = 0;
    dist[sy][sx] = 0;
    qy.push_back(sy); qx.push_back(sx);

    while (head < (int)qy.size()) {
        int y = qy[head], x = qx[head];
        head++;
        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d], nx = x + dx[d];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
            if (grid[ny][nx] == '#' || dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[y][x] + 1;
            qy.push_back(ny); qx.push_back(nx);
        }
    }
    return dist;
}

// cur : 현재 지점, cnt : 방문한 검사 지점 수, sum : 지금까지 이동 횟수
void dfs(int cur, int cnt, int sum) {
    if (sum >= best) return;                   // 가지치기
    if (cnt == P - 1) {                        // 검사 지점을 모두 방문
        int total = sum + D[cur][0];           // S로 복귀
        if (total < best) best = total;
        return;
    }
    for (int next = 1; next < P; next++) {     // 0번(S)은 후보가 아님
        if (used[next]) continue;
        used[next] = true;
        dfs(next, cnt + 1, sum + D[cur][next]);
        used[next] = false;                    // 되돌리기
    }
}

int solution(vector<string> grid) {
    int R = grid.size(), C = grid[0].size();

    // 1단계 : 지점 좌표 모으기 (S를 먼저 넣어 0번으로 고정)
    vector<int> py, px;
    for (int y = 0; y < R; y++)
        for (int x = 0; x < C; x++)
            if (grid[y][x] == 'S') { py.push_back(y); px.push_back(x); }
    for (int y = 0; y < R; y++)
        for (int x = 0; x < C; x++)
            if (grid[y][x] == 'P') { py.push_back(y); px.push_back(x); }
    P = py.size();

    // 2~3단계 : 지점마다 BFS 한 번 → 지점 사이 거리 표
    D.assign(P, vector<int>(P, 0));
    for (int i = 0; i < P; i++) {
        vector<vector<int>> dist = bfs(grid, py[i], px[i]);
        for (int j = 0; j < P; j++) {
            D[i][j] = dist[py[j]][px[j]];
            if (D[i][j] == -1) return -1;     // 도달할 수 없는 지점이 있으면 불가능
        }
    }

    // 4단계 : 모든 방문 순서를 백트래킹으로 탐색
    best = 1e9;
    used.assign(P, false);
    dfs(0, 0, 0);
    return best;
}
