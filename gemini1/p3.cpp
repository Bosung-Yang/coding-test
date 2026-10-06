#include <string>
#include <vector>

using namespace std;

// a가 b보다 먼저 수행되어야 하면 true
// 1. 소요 시간 짧은 순  2. 요청 시간 빠른 순  3. 작업 번호 작은 순
bool isAhead(const vector<int>& a, const vector<int>& b) {
    if (a[2] != b[2]) return a[2] < b[2];
    if (a[1] != b[1]) return a[1] < b[1];
    return a[0] < b[0];
}

// <queue>(우선순위 큐) 없이 매번 남은 작업을 전부 훑어서 고르는 방식
// 작업 수 n ≤ 10,000 → n² = 1억 번 비교라 C++로는 충분히 빠름
vector<int> solution(vector<vector<int>> jobs) {
    int n = jobs.size();
    vector<bool> done(n, false);
    vector<int> answer;
    int now = 0;   // 현재 시각

    for (int k = 0; k < n; k++) {
        // 1. 이미 요청된(요청 시간 ≤ now) 작업 중 규칙상 가장 앞선 작업
        int pick = -1;
        for (int i = 0; i < n; i++) {
            if (done[i] || jobs[i][1] > now) continue;
            if (pick == -1 || isAhead(jobs[i], jobs[pick])) pick = i;
        }

        // 2. 대기 중인 작업이 없으면, 가장 먼저 요청되는 시각으로 이동해서 다시 고름
        if (pick == -1) {
            int next = -1;
            for (int i = 0; i < n; i++) {
                if (!done[i] && (next == -1 || jobs[i][1] < next)) next = jobs[i][1];
            }
            now = next;
            for (int i = 0; i < n; i++) {
                if (done[i] || jobs[i][1] > now) continue;
                if (pick == -1 || isAhead(jobs[i], jobs[pick])) pick = i;
            }
        }

        // 3. 작업 수행
        done[pick] = true;
        now += jobs[pick][2];
        answer.push_back(jobs[pick][0]);
    }
    return answer;
}
