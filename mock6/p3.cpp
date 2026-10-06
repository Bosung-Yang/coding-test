#include <string>
#include <vector>

using namespace std;

// BFS 상태 : 위치 + 가진 카드 조합(비트마스크)
//   keys의 0번 비트 = 카드 a, 1번 비트 = 카드 b, 2번 비트 = 카드 c
//   예) keys = 5 (이진수 101) → a와 c를 가짐
struct Node {
    int y, x, keys;
};

int solution(vector<string> grid) {
    int R = grid.size(), C = grid[0].size();
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};

    int sy = 0, sx = 0;
    for (int y = 0; y < R; y++)
        for (int x = 0; x < C; x++)
            if (grid[y][x] == 'S') { sy = y; sx = x; }

    // dist[y][x][keys] : 카드 조합 keys를 가지고 (y, x)에 도착한 최소 이동 횟수
    // 카드 3종류 → 조합은 2^3 = 8가지
    vector<vector<vector<int>>> dist(R, vector<vector<int>>(C, vector<int>(8, -1)));

    vector<Node> q;          // vector + head 로 큐 구현
    int head = 0;
    dist[sy][sx][0] = 0;
    q.push_back({sy, sx, 0});

    while (head < (int)q.size()) {
        Node cur = q[head++];
        int d = dist[cur.y][cur.x][cur.keys];
        if (grid[cur.y][cur.x] == 'E') return d;

        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
            char ch = grid[ny][nx];
            if (ch == '#') continue;

            // 보안문 : 대응하는 카드 비트가 켜져 있어야 통과
            if (ch >= 'A' && ch <= 'C') {
                int need = 1 << (ch - 'A');
                if ((cur.keys & need) == 0) continue;
            }

            // 카드 칸 : 해당 비트를 켬 (이미 있으면 그대로)
            int nkeys = cur.keys;
            if (ch >= 'a' && ch <= 'c') nkeys |= 1 << (ch - 'a');

            if (dist[ny][nx][nkeys] != -1) continue;
            dist[ny][nx][nkeys] = d + 1;
            q.push_back({ny, nx, nkeys});
        }
    }
    return -1;
}
