#include <string>
#include <vector>

using namespace std;

struct Node {
    int y, x;
};

vector<int> solution(vector<string> grid) {
    int h = grid.size(), w = grid[0].size();
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    int regions = 0;   // 결함 영역 개수
    int largest = 0;   // 가장 큰 영역의 칸 수

    for (int sy = 0; sy < h; sy++) {
        for (int sx = 0; sx < w; sx++) {
            if (grid[sy][sx] != '#' || visited[sy][sx]) continue;

            // 새 영역 발견 → BFS로 크기 세기
            regions++;
            vector<Node> q;
            int head = 0;
            visited[sy][sx] = true;   // 시작점 방문 표시
            q.push_back({sy, sx});

            while (head < (int)q.size()) {
                Node cur = q[head++];
                // 8방향 (대각선 포함)
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        if (dy == 0 && dx == 0) continue;
                        int ny = cur.y + dy, nx = cur.x + dx;
                        if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                        if (grid[ny][nx] != '#' || visited[ny][nx]) continue;
                        visited[ny][nx] = true;
                        q.push_back({ny, nx});
                    }
                }
            }

            // 큐에 들어간 칸 수 = 영역 크기 (시작점 포함)
            int size = q.size();
            if (size > largest) largest = size;
        }
    }
    return {regions, largest};
}
