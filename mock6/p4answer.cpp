#include <string>
#include <vector>

using namespace std;

int n;                        // 인원 수
int teamSize;                 // 한 팀 인원 (n / 3)
int best;                     // 지금까지 찾은 최소 점수 차이
vector<vector<int>> syn;      // 협업 점수
vector<int> team;             // team[i] : i번 엔지니어의 팀 (0, 1, 2)
vector<int> cnt;              // cnt[t] : t팀에 배정된 인원

// 모든 사람의 팀이 정해졌을 때 점수 차이 계산
void evaluate() {
    int score[3] = {0, 0, 0};
    for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {          // 두 사람 쌍을 한 번씩만
            if (team[a] == team[b]) score[team[a]] += syn[a][b];
        }
    }
    int hi = score[0], lo = score[0];
    for (int t = 1; t < 3; t++) {
        if (score[t] > hi) hi = score[t];
        if (score[t] < lo) lo = score[t];
    }
    if (hi - lo < best) best = hi - lo;
}

// person번 엔지니어를 어느 팀에 넣을지 정함 (나눠 담기 백트래킹)
void dfs(int person) {
    if (person == n) { evaluate(); return; }

    for (int t = 0; t < 3; t++) {
        if (cnt[t] == teamSize) continue;   // 팀이 꽉 참

        team[person] = t;
        cnt[t]++;
        dfs(person + 1);
        cnt[t]--;                           // 되돌리기

        // 중복 제거 : 빈 팀에 넣어본 뒤에는 다른 빈 팀은 볼 필요 없음
        // (팀 번호는 의미가 없으므로 "0팀에 넣기"와 "1팀에 넣기"가 같은 경우)
        if (cnt[t] == 0) break;
    }
}

int solution(vector<vector<int>> synergy) {
    syn = synergy;
    n = synergy.size();
    teamSize = n / 3;
    best = 1e9;
    team.assign(n, -1);
    cnt.assign(3, 0);

    dfs(0);
    return best;
}
