#include <string>
#include <vector>


using namespace std;

vector<int> solution(vector<string> grid, vector<string> commands) {
    vector<int> answer;
    int R = grid.size();
    int C = grid[0].size();
    vector<int> dy = {-1,0,1,0};
    vector<int> dx = {0,1, 0, -1};
    int dir = 0;
    vector<vector<int>> visit(R, vector<int>(C,0));
    int cy, cx;
    for(int y = 0; y < R ; y++){
        for(int x = 0; x < C; x++){
            if (grid[y][x] == 'S'){
                cy = y; cx = x;
            }
        }
    }
    visit[cy][cx] = 1;
    for (string cmd : commands){
        if (cmd == "L"){
            dir--;
            if (dir < 0) dir = 3;
        }
        else if (cmd == "R"){
            dir++;
            if (dir >=4) dir = 0;
        }
        else{
            int k = stoi(cmd.substr(2,cmd.size()-2));
            int it = 0;
            while(it < k){
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];
                if (nx <0 || ny < 0 || nx >= C || ny >= R) break;
                if (grid[ny][nx] == '#') break;
                visit[ny][nx] = 1;
                cy = ny; cx = nx;
                it++;
            }
        }
    }

    int visitcnt = 0;
    for (int y = 0; y < R; y++){
        for (int x = 0; x < C ; x++){
            visitcnt+= visit[y][x];
        }
    }
    answer.push_back(cy);
    answer.push_back(cx);
    answer.push_back(visitcnt);
    return answer;
}
