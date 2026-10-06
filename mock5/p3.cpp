#include <string>
#include <vector>

using namespace std;

struct Node {
    int y, x;
};

int R, C;
vector<string> G;

// (sy, sx)에서 문자 goal이 있는 칸까지 최단 거리 (못 가면 -1)
int bfs(int sy, int sx, char goal) {
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};
    vector<vector<int>> dist(R, vector<int>(C, -1));
    vector<Node> q;
    int head = 0;
    dist[sy][sx] = 0;
    q.push_back({sy, sx});

    while (head < (int)q.size()) {
        Node cur = q[head++];
        if (G[cur.y][cur.x] == goal) return dist[cur.y][cur.x];
        for (int d = 0; d < 4; d++) {
            int ny = cur.y + dy[d], nx = cur.x + dx[d];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
            if (G[ny][nx] == '#' || dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[cur.y][cur.x] + 1;
            q.push_back({ny, nx});
        }
    }
    return -1;
}

// S → P 최단 거리 + P → E 최단 거리
// (S → P 경로 중에 E를 지나가도 도착이 아니므로, 두 구간을 따로 BFS)
int solution(vector<string> grid) {
    G = grid;
    R = grid.size();
    C = grid[0].size();

    int sy = 0, sx = 0, py = 0, px = 0;
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (grid[y][x] == 'S') { sy = y; sx = x; }
            if (grid[y][x] == 'P') { py = y; px = x; }
        }
    }

    int toP = bfs(sy, sx, 'P');
    if (toP == -1) return -1;
    int toE = bfs(py, px, 'E');
    if (toE == -1) return -1;
    return toP + toE;
}
