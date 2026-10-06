#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> grid, vector<string> commands) {
    int R = grid.size(), C = grid[0].size();

    // 북 → 동 → 남 → 서 (시계 방향), 0번 = 위쪽
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    int dir = 0;

    int y = 0, x = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (grid[i][j] == 'S') { y = i; x = j; }

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    visited[y][x] = true;
    int visitCount = 1;   // 시작 칸 포함

    for (const string& cmd : commands) {
        if (cmd == "L") {
            dir = (dir + 3) % 4;          // 왼쪽 90도
        }
        else if (cmd == "R") {
            dir = (dir + 1) % 4;          // 오른쪽 90도
        }
        else {                            // "F k"
            int k = stoi(cmd.substr(2));
            for (int step = 0; step < k; step++) {
                int ny = y + dy[dir], nx = x + dx[dir];
                // 벽이나 격자 밖이면 남은 전진 취소
                if (ny < 0 || nx < 0 || ny >= R || nx >= C || grid[ny][nx] == '#') break;
                y = ny;
                x = nx;
                if (!visited[y][x]) {
                    visited[y][x] = true;
                    visitCount++;
                }
            }
        }
    }
    return {y, x, visitCount};
}
