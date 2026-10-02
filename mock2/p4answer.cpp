#include <string>
#include <vector>

using namespace std;

int n, m;
vector<int> taskTime;            // 작업별 처리 시간
vector<vector<bool>> conflict;   // conflict[a][b] : a와 b는 같은 장비 불가
vector<int> assigned;            // assigned[i] : 작업 i를 배정한 장비 번호
vector<int> load;                // load[j] : 장비 j의 현재 처리 시간 합
int best;                        // 지금까지 찾은 최소 '최대 처리 시간'

// task번 작업을 배정할 차례, curMax : 지금까지 장비 처리 시간 중 최댓값
void dfs(int task, int curMax) {
    if (curMax >= best) return;               // 가지치기: 이미 최선보다 나쁨 (값은 줄지 않음)
    if (task == n) { best = curMax; return; } // 모든 작업 배정 완료

    for (int machine = 0; machine < m; machine++) {
        // 이미 이 장비에 배정된 작업 중 간섭하는 작업이 있으면 불가
        bool ok = true;
        for (int prev = 0; prev < task; prev++) {
            if (assigned[prev] == machine && conflict[prev][task]) { ok = false; break; }
        }
        if (!ok) continue;

        // 배정 → 재귀 → 원상 복구
        assigned[task] = machine;
        load[machine] += taskTime[task];
        int nextMax = load[machine] > curMax ? load[machine] : curMax;
        dfs(task + 1, nextMax);
        load[machine] -= taskTime[task];
        assigned[task] = -1;
    }
}

int solution(vector<int> times, int machines, vector<vector<int>> conflicts) {
    n = times.size();
    m = machines;
    taskTime = times;
    conflict.assign(n, vector<bool>(n, false));
    for (auto& c : conflicts) {
        conflict[c[0]][c[1]] = true;   // 간섭은 양방향
        conflict[c[1]][c[0]] = true;
    }
    assigned.assign(n, -1);
    load.assign(m, 0);
    best = 1e9;

    dfs(0, 0);

    // 한 번도 끝까지 배정하지 못했으면 불가능
    return best == 1e9 ? -1 : best;
}
