#include <string>
#include <vector>

using namespace std;

int n;
int maxVal, minVal;
vector<int> A;
vector<int> remain;   // remain[k] : 남은 연산자 개수 (0:+, 1:-, 2:×, 3:÷)

// idx번째 수를 붙일 차례, cur : 지금까지 계산 결과
void dfs(int idx, int cur) {
    if (idx == n) {
        if (cur > maxVal) maxVal = cur;
        if (cur < minVal) minVal = cur;
        return;
    }
    for (int k = 0; k < 4; k++) {
        if (remain[k] == 0) continue;

        int next;
        if (k == 0) next = cur + A[idx];
        else if (k == 1) next = cur - A[idx];
        else if (k == 2) next = cur * A[idx];
        else next = cur / A[idx];        // C++ 정수 나눗셈은 0 방향 버림 (-7 / 3 = -2)

        remain[k]--;
        dfs(idx + 1, next);
        remain[k]++;                     // 되돌리기
    }
}

vector<int> solution(vector<int> nums, vector<int> ops) {
    A = nums;
    n = nums.size();
    remain = ops;
    maxVal = -2000000000;
    minVal = 2000000000;

    dfs(1, nums[0]);                     // 첫 수는 그대로 시작
    return {maxVal, minVal};
}
