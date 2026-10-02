#include <string>
#include <vector>

using namespace std;

vector<vector<int>> visited;
int h,w;

int bfs(const vector<string>& grid, int sy, int sx){
    vector<int> dy = {-1, -1, -1, 0, 0, 1,1,1};
    vector<int> dx = {-1, 0, 1, -1, 1, -1, 0, 1};
    int cy = sy;
    int cx = sx;
    vector<vector<int>> q;
    int qhead = 0;
    q.push_back({cy,cx});
    visited[cy][cx] = 1;
    int answer = 1;
    while(qhead < q.size()){
        vector<int> cur = q[qhead++];
        cy = cur[0]; cx = cur[1];
        for (int dir = 0; dir < 8; dir++){
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (visited[ny][nx] == 1 || grid[ny][nx] == '.') continue;
            answer++;
            visited[ny][nx] = 1;
            q.push_back({ny,nx});
        }
    }
    return answer;
}
vector<int> solution(vector<string> grid) {
    vector<int> answer;
    h = grid.size();
    w = grid[0].size();
    visited.assign(h, vector<int>(w,0));
    int cnt = 0; // 결함 영역의 개수 
    int best = 0; // 가장 큰 결함의 캐수

    for (int y = 0; y < h ; y++){
        for (int x = 0; x < w; x++){
            if (grid[y][x] == '#' && visited[y][x] ==0){
                int rval = bfs(grid, y, x);
                cnt++;
                best = (best > rval) ? best : rval;
            }
        }
    }
    answer.push_back(cnt);
    answer.push_back(best);
    return answer;
}
