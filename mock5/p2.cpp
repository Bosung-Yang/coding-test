#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    char before = s[0];
    int cnt = 1;
    for (int idx = 1; idx < s.size(); idx++){
        if(s[idx] == before) cnt++;
        else if (s[idx] != before){
            if (cnt == 1){
                answer += before;
            }
            else{
                answer += before + to_string(cnt);
            }
            before = s[idx];
            cnt = 1;
        }
    }
    if (before == s[s.size()-1]){
        if (cnt == 1){
            answer += before;
        }
        else{
            answer += before + to_string(cnt);
        }
    }

    return answer;
}
