#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

int gettime(string t){
    return stoi(t.substr(0,2)) * 60 + stoi(t.substr(3,5));
}
vector<string> solution(vector<string> logs) {
    vector<string> answer;

    map<string, int> usetime;
    map<string, int> ontime; 
    //vector<string> eq_name;

    vector<vector<string>> log;

    for (string l : logs){
        string equipname, time, type;
        stringstream ss(l);
        ss >> equipname >> time >> type; 
        log.push_back({equipname, time, type});
        answer.push_back(equipname);
    }
    sort(log.begin(), log.end(), [](vector<string>& a, vector<string>& b){return a[1] < b[1];});

    for (vector<string> l : log){
        if (l[2] == "ON"){
            ontime[l[0]] = gettime(l[1]);
        }
        else if (l[2] == "OFF"){
            usetime[l[0]] += gettime(l[1]) - ontime[l[0]];
        }
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    sort(answer.begin(), answer.end(),
    [&](string& a , string& b){
        if (usetime[a] != usetime[b]) return usetime[a] > usetime[b];
        return a < b;
    });

    return answer;
}
