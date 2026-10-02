#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> readings, int t) {
    vector<int> answer;
    int alert_cnt = 0;
    int best = 0;
    int cur = 0;
    for (int idx = 0 ; idx <  readings.size(); idx++){
        int read = readings[idx];
        if (read > t){
            cur++;
            if (cur == 1) alert_cnt++;
            if (cur > best) best = cur;
        }
        else{
            cur = 0;
        }
    }
    answer.push_back(alert_cnt);
    answer.push_back(best);
    return answer;
}
