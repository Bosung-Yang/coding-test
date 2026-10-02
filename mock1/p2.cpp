#include <string>
#include <vector>

using namespace std;

int answer = 1e9;
vector<bool> visited(10, false);
void dfs(vector<vector<int>>& cost, vector<vector<int>>& order, int cur, int costsum){
    int cnt = 0;
    for (bool v : visited){
        if (v == true) cnt++;
    }
    if (cnt == cost.size()){
        answer = min(answer, costsum);
        return;
    }

    for(int i = 0 ; i < cost.size(); i++){
        bool skipflag = false;
        for (vector<int> o : order){
            if (o == {i, cur}) skipflag = true;
        }
        if (skipflag) continue;
        if (visited[i] == false){
            visited[i] = true;
            costsum += cost[i][j];
            dfs(cost, order, i, costnum);
            visited[i] = false;
        }
    }
}


int solution(vector<vector<int>> cost, vector<vector<int>> order) {

    return answer;
}
