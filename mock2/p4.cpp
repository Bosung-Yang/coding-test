#include <string>
#include <vector>

using namespace std;

int n, m;
vector<int> taskTime;
vector<vector<bool>> conflict;   // conflict[a][b] : a와 b는 같은 장비 불가
vector<int> assigned;            // assigned[i] : 작업 i를 배정한 장비
vector<int> load;                // load[j] : 장비 j의 처리 시간 합
int best;

// 나눠 담기 백트래킹 : task번 작업을 어느 장비에 줄지 정함
// curMax : 지금까지 장비 처리 시간 중 최댓값
void dfs(int task, int curMax) {
    if (curMax >= best) return;                 // 가지치기 (최댓값은 줄지 않음)
    if (task == n) { best = curMax; return; }

    for (int mc = 0; mc < m; mc++) {
        // 이 장비에 이미 배정된 작업 중 간섭하는 것이 있으면 불가
        bool ok = true;
        for (int prev = 0; prev < task; prev++) {
            if (assigned[prev] == mc && conflict[prev][task]) { ok = false; break; }
        }
        if (!ok) continue;

        assigned[task] = mc;
        load[mc] += taskTime[task];
        int nextMax = load[mc] > curMax ? load[mc] : curMax;
        dfs(task + 1, nextMax);
        load[mc] -= taskTime[task];             // 되돌리기 (쌓는 값)
    }
}

int solution(vector<int> times, int machines, vector<vector<int>> conflicts) {
    n = times.size();
    m = machines;
    taskTime = times;
    conflict.assign(n, vector<bool>(n, false));
    for (const vector<int>& c : conflicts) {
        conflict[c[0]][c[1]] = true;   // 간섭은 양방향
        conflict[c[1]][c[0]] = true;
    }
    assigned.assign(n, -1);
    load.assign(m, 0);
    best = 1e9;

    dfs(0, 0);
    return best == 1e9 ? -1 : best;
}
