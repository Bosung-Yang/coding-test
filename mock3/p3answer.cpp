#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> grid, int k) {
    int R = grid.size();
    int C = grid[0].size();
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};
    int rounds = 0, removedTotal = 0;

    while (true) {
        // 1. 크기 k 이상인 덩어리 찾기 (지울 칸은 toRemove에 표시만 하고, 아직 지우지 않음)
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        vector<vector<bool>> toRemove(R, vector<bool>(C, false));
        bool found = false;

        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                if (grid[y][x] == '.' || visited[y][x]) continue;

                // (y, x)와 같은 종류로 연결된 덩어리를 BFS로 모음
                char kind = grid[y][x];
                vector<int> qy, qx;
                int head = 0;
                visited[y][x] = true;
                qy.push_back(y); qx.push_back(x);

                while (head < (int)qy.size()) {
                    int cy = qy[head], cx = qx[head];
                    head++;
                    for (int d = 0; d < 4; d++) {
                        int ny = cy + dy[d], nx = cx + dx[d];
                        if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
                        if (visited[ny][nx] || grid[ny][nx] != kind) continue;
                        visited[ny][nx] = true;
                        qy.push_back(ny); qx.push_back(nx);
                    }
                }

                // 큐에 들어간 칸들이 곧 덩어리 → 크기 k 이상이면 제거 대상
                if ((int)qy.size() >= k) {
                    found = true;
                    for (int i = 0; i < (int)qy.size(); i++) toRemove[qy[i]][qx[i]] = true;
                }
            }
        }

        if (!found) break;    // 제거할 덩어리가 없으면 종료
        rounds++;

        // 2. 표시한 칸을 동시에 제거
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                if (toRemove[y][x]) {
                    grid[y][x] = '.';
                    removedTotal++;
                }
            }
        }

        // 3. 낙하 : 각 열을 아래에서부터 보며, 블록을 아래쪽 빈 자리부터 채움
        for (int x = 0; x < C; x++) {
            int bottom = R - 1;                       // 다음 블록이 놓일 위치
            for (int y = R - 1; y >= 0; y--) {
                if (grid[y][x] == '.') continue;
                char block = grid[y][x];
                grid[y][x] = '.';
                grid[bottom][x] = block;              // bottom == y 이면 제자리
                bottom--;
            }
        }
    }

    return {rounds, removedTotal};
}
