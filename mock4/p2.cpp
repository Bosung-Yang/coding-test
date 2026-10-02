#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> codes) {
    vector<int> answer;
    for (int idx = 0; idx < codes.size(); idx++){
        string code = codes[idx];
        if (code.size() != 9){
            answer.push_back(idx);
            continue;
        }
        if (code[0] < 'A' || code[0] > 'Z' || code[1] < 'A' || code[1] > 'Z'){
            answer.push_back(idx);
            continue;
        }
        if (code[2] != '-' || code[7] != '-'){
            answer.push_back(idx);
            continue;
        }
        bool numerror = false;
        for (int cidx = 3; cidx < 7; cidx++){
            if (code[cidx] < '0' || code[cidx] > '9'){
                numerror = true; break;
            }
        }
        if (numerror){
                answer.push_back(idx);
                continue;
            }
        int sum = 0;
        for (int cidx = 3; cidx < 7; cidx++){
            sum += int(code[cidx] - '0');
        }
        int r = sum % 26;
        if (code[8] != 'A'+r){
            answer.push_back(idx);
            continue;
        }
        
    }
    if (answer.size() == 0){
        answer.push_back(-1);
    }
    return answer;
}
