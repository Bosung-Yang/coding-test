#include <string>
#include <vector>

using namespace std;
int answer = 1e9;
vector<int> used;
vector<int> costarr;
vector<int> powerarr;
vector<vector<int>> confarr;
void dfs(int needPower, int curPower, int curCost, int start){
    if (curPower >= needPower){
        answer = (answer < curCost) ? answer : curCost;
        return;
    }
    for (int idx = start; idx < costarr.size(); idx++){
        if (used[idx] == 1) continue;
        bool conflag = false;

        for (vector<int> c : confarr){
            if (idx == c[0] && used[c[1]] == 1){
                conflag = true; break;
            }
            if (idx == c[1] && used[c[0]] == 1){
                conflag = true; break;
            }
        }
        if (conflag) continue;
        if (curCost+costarr[idx] > answer) continue;
        // select
        used[idx] = 1;
        dfs(needPower, curPower+powerarr[idx], curCost+costarr[idx], idx);
        used[idx] = 0;
    }

}
int solution(vector<int> cost, vector<int> power, int needPower, vector<vector<int>> conflicts) {
    costarr = cost; powerarr = power; confarr = conflicts;
    used.assign(cost.size(), 0);
    dfs(needPower, 0, 0, 0);
    if (answer == 1e9) answer = -1;
    return answer;
}
