#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> scores, int limit, int K) {
    int discarded = 0;   // 폐기되는 가로줄 수

    for (const vector<int>& row : scores) {
        // 이 행의 불량 칩 수 (limit '미만'이 불량)
        int bad = 0;
        for (int score : row) {
            if (score < limit) bad++;
        }
        // 불량 칩이 K개 '이상'이면 폐기
        if (bad >= K) discarded++;
    }
    return discarded;
}
