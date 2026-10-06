#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> readings, int t) {
    int count = 0;   // 경보 구간 개수
    int best = 0;    // 가장 긴 경보 구간 길이
    int run = 0;     // 현재 연속 경보 길이

    for (int i = 0; i < (int)readings.size(); i++) {
        if (readings[i] > t) {            // t '초과'면 경보
            run++;
            if (run == 1) count++;        // 새 구간 시작
            if (run > best) best = run;
        } else {
            run = 0;                      // 구간 끊김
        }
    }
    return {count, best};
}
