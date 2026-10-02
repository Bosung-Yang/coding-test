#include <string>
#include <vector>
#include <queue>

using namespace std;
int h, w;
vector<int> dy = {1,-1,0,0};
vector<int> dx = {0,0,1,-1};
const int INF = 1e9;

int solution(vector<string> grid) {
    int sy, sx;
    h = grid.size(); w = grid[0].size();

    // gasTime[y][x] : 그 칸에 가스가 도착하는 시각 (안 오면 INF)
    vector<vector<int>> gasTime(h, vector<int>(w, INF));
    queue<pair<int,int>> q;

    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            if (grid[y][x] == 'S') { sy = y; sx = x; }
            if (grid[y][x] == 'G') { gasTime[y][x] = 0; q.push({y, x}); } // 모든 G를 동시에 시작
        }
    }

    // ① 가스 BFS : '.'와 'S'로만 퍼짐
    while (!q.empty()){
        auto [y, x] = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (grid[ny][nx] != '.' && grid[ny][nx] != 'S') continue;
            if (gasTime[ny][nx] != INF) continue;           // 이미 더 빨리 도착함
            gasTime[ny][nx] = gasTime[y][x] + 1;
            q.push({ny, nx});
        }
    }

    // ② 작업자 BFS : dist[y][x] = 그 칸에 도착하는 최소 시각 (-1이면 미방문)
    vector<vector<int>> dist(h, vector<int>(w, -1));
    dist[sy][sx] = 0;
    q.push({sy, sx});

    while (!q.empty()){
        auto [y, x] = q.front(); q.pop();
        if (grid[y][x] == 'E') return dist[y][x];         // BFS라 처음 도착이 최단 시간

        for (int dir = 0; dir < 4; dir++){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            int t = dist[y][x] + 1;                         // 다음 칸 도착 시각
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (grid[ny][nx] == '#' || grid[ny][nx] == 'G') continue;
            if (dist[ny][nx] != -1) continue;
            // 가스가 먼저 퍼지므로, t분에 가스가 오는 칸에는 t분에 못 들어감
            if (grid[ny][nx] != 'E' && gasTime[ny][nx] <= t) continue;
            dist[ny][nx] = t;
            q.push({ny, nx});
        }
    }
    return -1;   // 비상구에 도착 못 함
}
