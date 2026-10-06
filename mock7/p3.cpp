#include <string>
#include <vector>

using namespace std;

struct Node {
    int y, x;
};

int solution(vector<string> grid) {
    int R = grid.size(), C = grid[0].size();
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};

    // dist[y][x] : 그 칸이 오염되는 시각 (-1 = 오염 안 됨)
    vector<vector<int>> dist(R, vector<int>(C, -1));
    vector<Node> q;
    int head = 0;

    // 다중 시작점 BFS : 모든 V를 처음부터 큐에 넣음 → "동시에 퍼짐"이 자동으로 처리됨
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (grid[y][x] == 'V') {
                dist[y][x] = 0;
                q.push_back({y, x});
            }
        }
    }

    while (head < (int)q.size()) {
        Node cur = q[head++];
        for (int d = 0; d < 4; d++) {
            int ny = cur.y + dy[d], nx = cur.x + dx[d];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
            if (grid[ny][nx] != '.' || dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[cur.y][cur.x] + 1;
            q.push_back({ny, nx});
        }
    }

    // 깨끗했던 칸 중 가장 늦게 오염된 시각 = 답 (하나라도 안 되면 -1)
    int answer = 0;
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (grid[y][x] != '.') continue;
            if (dist[y][x] == -1) return -1;
            if (dist[y][x] > answer) answer = dist[y][x];
        }
    }
    return answer;   // 깨끗한 칸이 없으면 0
}
