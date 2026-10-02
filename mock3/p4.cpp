#include <string>
#include <vector>

using namespace std;



vector<int> bfs(vector<string> grid, vector<pair<int,int>> start, vector<pair<int,int>> goal){
    vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), -1)); 
    auto [cx, cy] = start;
    vector<int> q;
    int qhead = 0;
    dist[cy,cx] = 0;
    q.push_back({cy,cx})
    vector<int> dy = {1,-1,0,0};
    vector<int> dx = {0,0,1,-1};
    while(qhead < q.size()){
        auto [cy, cx] = q[qhead++];
        for (int dir = 0; dir<4; dir++){
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];
            if (ny < 0 || nx < 0 || ny >= grid.size() || nx >= grid[0].size()) continue;
            if (grid[ny][nx] == '#' || visit[ny][nx] != -1) continue;
            visit[ny][nx] = visit[cy][cx] + 1;
            cy = ny; cx = nx;
            if (ny == goal[0] && nx == goal[1]) break;
            q.push_back({cy,cx});
        }
    }

    return {cy,cx,dist[cy][cx]};
}

int solution(vector<string> grid) {
    int answer = 0;

    for (int y = 0 ; y < grid.size(); y++){
        for (int x = 0; y )
    }
    return answer;
}
