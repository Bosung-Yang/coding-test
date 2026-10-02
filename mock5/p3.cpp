#include <string>
#include <vector>

using namespace std;

int h,w;

int bfs(vector<string> grid, int sy, int sx, int ey, int ex){
    vector<vector<int>> dist(h,vector<int>(w,-1));
    vector<int> dy = {1,-1,0,0};
    vector<int> dx = {0,0,1,-1};

    vector<vector<int>> q;
    int qhead = 0;

    dist[sy][sx] = 0;
    q.push_back({sy,sx});

    while(qhead < q.size()){
        vector<int> cur = q[qhead++];
        int cy = cur[0]; int cx = cur[1];
        for (int dir=0; dir<4; dir++){
            int ny = cy + dy[dir]; int nx = cx+dx[dir];
            if (ny < 0 || nx < 0 || ny >= h || nx >=w) continue;
            if (dist[ny][nx] != -1 || grid[ny][nx] == '#') continue;
            dist[ny][nx] = dist[cy][cx] + 1;
            q.push_back({ny, nx});
        }
    }
    return dist[ey][ex];
}
int solution(vector<string> grid) {
    int answer = 0;
    h = grid.size(); w = grid[0].size();
    int sy,sx,py,px,ey,ex;
    for(int y = 0; y < h; y++){
        for(int x = 0 ; x < w; x++){
            if (grid[y][x] == 'S') {sy = y; sx = x;}
            if (grid[y][x] == 'E') {ey = y; ex = x;}
            if (grid[y][x] == 'P') {py = y; px = x;}
        }
    }
    
    int p_val = bfs(grid, sy, sx, py, px);
    int e_val = bfs(grid, py, px, ey, ex);
    if (p_val == -1 || e_val == -1) return -1;
    return p_val + e_val;

    return answer;
}
