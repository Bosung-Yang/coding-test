#include <string>
#include <vector>
#include <queue>
using namespace std;

int h, w;
vector<int> dy = {1,-1,0,0};
vector<int> dx = {0,0,1,-1};

int bfs(vector<string> grid, int k, vector<int> start, vector<int> end){

    vector<vector<int>> dist(h, (w, vector<int>0));
    
}

int solution(vector<string> grid, int k) {
    int answer = 0;
    h = grid.size(); w = grid[0].size();
    int sy, sx, ey, ex;
    for (int y = 0; y < h; y++){
        for (int x = 0 ; x < w; x++){
            if (grid[y][x] == 'S'){
                sy = y; sx = x;    
            }
            if (grid[y][x] == 'E'){
                ey = y; ex = x;
            }
        }
    }

    return answer;
}
