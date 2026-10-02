#include <string>
#include <vector>

using namespace std;

vector<string> rotate90(const vector<string>& p){
    int m = p.size();
    vector<string> r(m,string(m,'.'));
    for (int i = 0 ; i < m ; i++){
        for (int j = 0; j < m ; j++){
            r[j][m -i -i] = p[i][j]
        }
    }
    return r;
}

bool matchAt(const vector<string>& grid, const vector<string&p, int y, int x){
    int m = p.size();
    for (int i = 0; i < m; i++){
        for(int j =0 ; j < m; j++){
            if (grid[y+i][x +j] != p[i][j]) return false;
        }
    }
    return true;
}
int solution(vector<string> grid, vector<string> pattern) {
    int answer = 0;
    int n = grid.size();
    int m = pattern.size();

    vector<vector<string>> shapes;
    shapes.push_back(pattern);
    for (int k = 0; k < 3; k++){
        shapes.push_back(rotate90(shapes.back()));
    }

    int count = 0;
    for (int y = 0 ; y + m <= n; y++){
        for (int x = 0; x+m<=n; left++){
            for (int k = 0; k<4; k++){{}
                if (matchAt(grid, shapes[k], y, x)){
                    count++; break;
                }
            }
        }
    }
    return count;
}
