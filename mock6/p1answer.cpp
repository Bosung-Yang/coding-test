#include <string>
#include <vector>

using namespace std;

// M×M 패턴을 시계 방향으로 90도 회전한 결과를 반환
// 원래 (i, j) 칸 → 회전 후 (j, m-1-i) 칸
vector<string> rotate90(const vector<string>& p) {
    int m = p.size();
    vector<string> r(m, string(m, '.'));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            r[j][m - 1 - i] = p[i][j];
        }
    }
    return r;
}

// grid의 (top, left)부터 시작하는 M×M 부분이 p와 완전히 같은지 확인
bool matchAt(const vector<string>& grid, const vector<string>& p, int top, int left) {
    int m = p.size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[top + i][left + j] != p[i][j]) return false;
        }
    }
    return true;
}

int solution(vector<string> grid, vector<string> pattern) {
    int n = grid.size();
    int m = pattern.size();

    // 1. 0도, 90도, 180도, 270도 회전 모양을 미리 만들어 둠
    vector<vector<string>> shapes;
    shapes.push_back(pattern);
    for (int k = 0; k < 3; k++) {
        shapes.push_back(rotate90(shapes.back()));   // 직전 모양을 한 번 더 회전
    }

    // 2. 가능한 모든 왼쪽 위 위치에서 네 모양 중 하나라도 일치하면 카운트
    int count = 0;
    for (int top = 0; top + m <= n; top++) {
        for (int left = 0; left + m <= n; left++) {
            for (int k = 0; k < 4; k++) {
                if (matchAt(grid, shapes[k], top, left)) {
                    count++;
                    break;    // 한 위치는 한 번만 셈
                }
            }
        }
    }
    return count;
}
