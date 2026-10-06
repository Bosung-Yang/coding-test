#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> production) {
    int n = production.size();      // 라인 수
    int m = production[0].size();   // 날짜 수

    // 1. 라인별 합 (행 합) — 같으면 번호가 작은 것을 유지하려고 '>'만 사용
    int bestLine = 0, bestLineSum = -1;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) sum += production[i][j];
        if (sum > bestLineSum) { bestLineSum = sum; bestLine = i; }
    }

    // 2. 날짜별 합 (열 합)
    int bestDay = 0, bestDaySum = -1;
    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) sum += production[i][j];
        if (sum > bestDaySum) { bestDaySum = sum; bestDay = j; }
    }

    return {bestLine, bestDay};
}
