#include <string>
#include <vector>

using namespace std;

// BFS 상태 : 위치 (y, x) + 지금까지 사용한 보호막 수
struct Node {
    int y, x, used;
};

int solution(vector<string> grid, int k) {
    int h = grid.size(), w = grid[0].size();
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};

    int sy = 0, sx = 0;
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            if (grid[y][x] == 'S') { sy = y; sx = x; }

    // dist[y][x][used] : 보호막 used개를 쓰고 (y, x)에 도착한 최소 이동 횟수 (-1 = 미방문)
    // 같은 칸이라도 남은 보호막이 다르면 이후 갈 수 있는 길이 달라지므로 따로 기록
    vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(k + 1, -1)));

    vector<Node> q;      // <queue> 대신 vector + head
    int head = 0;
    dist[sy][sx][0] = 0;
    q.push_back({sy, sx, 0});

    while (head < (int)q.size()) {
        Node cur = q[head++];
        int d = dist[cur.y][cur.x][cur.used];
        if (grid[cur.y][cur.x] == 'E') return d;   // 처음 도착 = 최소 이동

        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.y + dy[dir], nx = cur.x + dx[dir];
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (grid[ny][nx] == '#') continue;

            int nused = cur.used + (grid[ny][nx] == 'L' ? 1 : 0);   // 레이저면 보호막 소모
            if (nused > k) continue;                                 // 보호막 부족
            if (dist[ny][nx][nused] != -1) continue;                 // 같은 상태로 방문함

            dist[ny][nx][nused] = d + 1;
            q.push_back({ny, nx, nused});
        }
    }
    return -1;
}
