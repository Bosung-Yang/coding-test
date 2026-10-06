#include <string>
#include <vector>

using namespace std;

// 투 포인터 (슬라이딩 윈도우)
// [left, right] 구간 안의 0의 개수가 C 이하이면, 그 0을 모두 복구해서 전부 1로 만들 수 있음
// right를 한 칸씩 늘리고, 0이 C개를 넘으면 left를 줄여서 구간을 유지
int solution(vector<int> process, int C) {
    int n = process.size();
    int left = 0;
    int zeros = 0;   // 현재 구간 안의 0 개수
    int best = 0;

    for (int right = 0; right < n; right++) {
        if (process[right] == 0) zeros++;

        // 0이 너무 많으면 왼쪽을 당겨서 줄임
        while (zeros > C) {
            if (process[left] == 0) zeros--;
            left++;
        }

        int len = right - left + 1;
        if (len > best) best = len;
    }
    return best;
}
