#include <string>
#include <vector>

using namespace std;

// 올바른 장비 코드 "XX-NNNN-C" 인지 검사
bool isValid(const string& code) {
    if (code.size() != 9) return false;                      // 1. 길이부터 확인 (범위 밖 접근 방지)

    for (int i = 0; i < 2; i++) {                            // 2. 대문자 두 글자
        if (code[i] < 'A' || code[i] > 'Z') return false;
    }
    if (code[2] != '-' || code[7] != '-') return false;      // 3. 하이픈

    int sum = 0;
    for (int i = 3; i <= 6; i++) {                           // 4. 숫자 네 글자 + 합
        if (code[i] < '0' || code[i] > '9') return false;
        sum += code[i] - '0';
    }
    return code[8] == 'A' + sum % 26;                        // 5. 검증 문자 (합을 다 구한 뒤)
}

vector<int> solution(vector<string> codes) {
    vector<int> answer;
    for (int i = 0; i < (int)codes.size(); i++) {
        if (!isValid(codes[i])) answer.push_back(i);
    }
    if (answer.empty()) answer.push_back(-1);
    return answer;
}
