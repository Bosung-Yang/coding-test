#include <string>
#include <vector>

using namespace std;

int answer = -1;
int n;
vector<vector<int>> people;

void dfs(vector<vector<int>>& grid, int k, int now, int sum){
    if (k == now){
        answer = (answer > sum) ? answer : sum;
        return;
    }
    vector<int> dy = {1,-1,0,0};
    vector<int> dx = {0,0,1,-1};

    for (int y = 1; y <= n; y++){
        for (int x = 1; x <= n; x++){
            if (grid[y][x] == 0 || people[y][x] == 1) continue;
            bool conti_flag = false;
            int part_sum = grid[y][x];
            for (int dir = 0; dir < 4; dir++){
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if(people[ny][nx] == 1) conti_flag = true;
            }
            if (conti_flag) continue;
            people[y][x] = 1;
            dfs(grid, k, now+1, sum+part_sum);
            people[y][x] = 0;
        }
    }
}


int solution(vector<vector<int>> grid, int k) {
    n = grid.size();
    people.assign(n+2, vector<int>(n+2,0));
    vector<vector<int>> n_grid(n+2, vector<int>(n+2,0));
    for (int y = 1; y <= n; y++){
        for (int x = 1; x <= n; x++){
            n_grid[y][x] = grid[y-1][x-1];
        }
    }
    dfs(n_grid, k, 0, 0);
    return answer;
}
