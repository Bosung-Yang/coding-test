#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 1e9;
vector<bool> visited(10, false);

// cur : 마지막으로 수행한 공정 (아직 없으면 -1), costsum : 지금까지 전환 비용
void dfs(vector<vector<int>>& cost, vector<vector<int>>& order, int cur, int costsum){
    // 모든 공정을 다 골랐으면 최솟값 갱신
    int cnt = 0;
    for (bool v : visited){
        if (v == true) cnt++;
    }
    if (cnt == cost.size()){
        answer = min(answer, costsum);
        return;
    }

    for (int i = 0; i < cost.size(); i++){
        if (visited[i] == true) continue;

        // i보다 먼저 와야 하는 공정(o[0])이 아직 안 끝났으면 i는 지금 못 고름
        bool skipflag = false;
        for (vector<int>& o : order){
            if (o[1] == i && visited[o[0]] == false) skipflag = true;
        }
        if (skipflag) continue;

        visited[i] = true;
        int add = (cur == -1) ? 0 : cost[cur][i];   // 첫 공정은 비용 0
        dfs(cost, order, i, costsum + add);
        visited[i] = false;
    }
}

int solution(vector<vector<int>> cost, vector<vector<int>> order) {
    answer = 1e9;
    visited.assign(10, false);

    dfs(cost, order, -1, 0);

    // 끝까지 완성된 순서가 없으면 선후 관계에 사이클이 있는 것
    if (answer == 1e9) return -1;
    return answer;
}
