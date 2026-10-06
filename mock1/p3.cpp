#include <string>
#include <vector>

using namespace std;

struct Node {
    int y, x;
};

const int INF = 1e9;

int solution(vector<string> grid) {
    int h = grid.size(), w = grid[0].size();
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};

    // gasTime[y][x] : 그 칸에 가스가 도착하는 시각 (안 오면 INF)
    vector<vector<int>> gasTime(h, vector<int>(w, INF));
    vector<Node> q;
    int head = 0;
    int sy = 0, sx = 0;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (grid[y][x] == 'S') { sy = y; sx = x; }
            if (grid[y][x] == 'G') {          // 모든 G를 동시에 시작 (다중 시작점 BFS)
                gasTime[y][x] = 0;
                q.push_back({y, x});
            }
        }
    }

    // ① 가스 BFS : '.'와 'S'로만 퍼짐
    while (head < (int)q.size()) {
        Node cur = q[head++];
        for (int d = 0; d < 4; d++) {
            int ny = cur.y + dy[d], nx = cur.x + dx[d];
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (grid[ny][nx] != '.' && grid[ny][nx] != 'S') continue;
            if (gasTime[ny][nx] != INF) continue;
            gasTime[ny][nx] = gasTime[cur.y][cur.x] + 1;
            q.push_back({ny, nx});
        }
    }

    // ② 작업자 BFS : dist[y][x] = 도착 시각 (-1 = 미방문)
    vector<vector<int>> dist(h, vector<int>(w, -1));
    q.clear();
    head = 0;
    dist[sy][sx] = 0;
    q.push_back({sy, sx});

    while (head < (int)q.size()) {
        Node cur = q[head++];
        if (grid[cur.y][cur.x] == 'E') return dist[cur.y][cur.x];

        for (int d = 0; d < 4; d++) {
            int ny = cur.y + dy[d], nx = cur.x + dx[d];
            int t = dist[cur.y][cur.x] + 1;            // 다음 칸 도착 시각
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (grid[ny][nx] == '#' || grid[ny][nx] == 'G') continue;
            if (dist[ny][nx] != -1) continue;
            // 가스가 먼저 퍼지므로, t분에 가스가 오는 칸에는 t분에 못 들어감
            if (grid[ny][nx] != 'E' && gasTime[ny][nx] <= t) continue;
            dist[ny][nx] = t;
            q.push_back({ny, nx});
        }
    }
    return -1;
}
