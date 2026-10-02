#include <string>
#include <vector>

using namespace std;

vector<vector<int>> syn;
vector<int> team;
vector<int> cnt;
int n;
int teamSize;
int best;

void evaluate(){
    int score[3] = {0,0,0};
    for (int a = 0; a < n; a++){
        for (int b = a+1; b<n; b++){
            if (team[a] == team[b]) score[team[a]] += syn[a][b];
        }
    }

    int hi = score[0], lo = score[0];
    for (int t = 1; t <3; t++){
        if (score[t] > hi) hi = score[t];
        if (score[t] < lo) lo = score[t];
    }
    if (hi-lo < best) best = hi-lo;
}

vector<int> dfs(int person){
    if (person == n){
        evaluate(); return;
    }
    
    for (int teamnumber = 0; teamnumber <2; teamnumber++){
        teamnumber[person] = t;
        cnt[teamnumber]++;
        dfs(person+1);
        cnt[teamnumber]--;
        if (cnt[teamnumber] == 0) break;
    }
}

int solution(vector<vector<int>> synergy) {
    syn = synergy;
    n = synergy.size()
    teamSize = n/3;
    best = 1e9;
    team.assign(syn.size(), -1);
    cnt.assign(3,0)
    dfs(0)
    return answer;
}
