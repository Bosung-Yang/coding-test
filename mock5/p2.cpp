#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int n = s.size();
    int i = 0;

    while (i < n) {
        // s[i]와 같은 문자가 어디까지 이어지는지 찾기
        int j = i;
        while (j < n && s[j] == s[i]) j++;
        int count = j - i;                       // 연속 길이

        answer += s[i];
        if (count > 1) answer += to_string(count);   // 1번이면 횟수 생략

        i = j;                                   // 다음 묶음으로
    }
    return answer;
}
