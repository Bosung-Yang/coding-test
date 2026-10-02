#include <string>
#include <vector>
#include <queue>

using namespace std;
int h,w;
vector<int> dy = {1,-1,0,0};
vector<int> dx = {0,0,1,-1};
int answer = 1e9;
void dfs(vector<string>& grid, vector<int> cur, vector<int> goal, int m){
    // end condition
    if (cur[0] == goal[0] && cur[1] == goal[1]){
        if (m < answer) answer = m;
        return;
    }

    // gas spread
    vector<string> aftergas = grid; 
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            if (grid[y][x] == 'G'){
                for (int dir = 0; dir < 4; dir++){
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];
                    if (ny >= 0 && nx >= 0 && ny < h && nx < w &&
                        (grid[ny][nx] != '#' && grid[ny][nx] != 'E')){
                            aftergas[ny][nx] = 'G';
                        }
                }
            }
        }
    }

    // recursive function call
    for (int dir = 0; dir< 4; dir++){
        int ny = cur[0] + dy[dir];
        int nx = cur[1] + dx[dir];
        if (ny >= 0 && nx >= 0 && ny < h && nx < w &&
            (aftergas[ny][nx] != '#' && aftergas[ny][nx] != 'G')){
                dfs(aftergas, {ny,nx}, goal, m+1);
            }
    }
}

int solution(vector<string> grid) {
    
    int sy, sx, ey, ex;
    h = grid.size(); w = grid[0].size();
    for (int y = 0 ; y < h ; y++){
        for (int x = 0; x < w; x++){
            if (grid[y][x] == 'S') {sy = y; sx = x;};
            if (grid[y][x] == 'E') {ey = y; ex = x;};
        }
    }
    dfs(grid, {sy,sx}, {ey,ex}, 0);
    if (answer == 1e9) answer = -1;
    return answer;
}
