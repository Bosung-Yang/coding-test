#include <string>
#include <vector>

using namespace std;

vector<string> split(const string& s, char sep = ' ') {
    vector<string> result;
    size_t start = 0, pos;
    while ((pos = s.find(sep, start)) != string::npos) {
        result.push_back(s.substr(start, pos - start));
        start = pos + 1;
    }
    result.push_back(s.substr(start));
    return result;
}

vector<int> solution(int n, vector<string> commands) {
    vector<int> answer;

    vector<int> mymem(n, 1001); // 1001 == 할당안됨 

    for (string cmd : commands){
        vector<string> tmp = split(cmd);
        char type = tmp[0][0];
        int id = stoi(tmp[1]);

        if (type == 'A'){
            int start = 0;
            int cnt = 0;
            int idx = 0; 
            int size = stoi(tmp[2]);
            bool success = false;
            while(idx < n ){
                if (mymem[idx] == 1001){
                    cnt++; 
                    if (cnt == 1) start = idx; 
                    idx++;
                }
                else if(mymem[idx] != 1001) { cnt = 0 ; idx++;}
                if (cnt == size) {success = true; break;}
                
            }
            if (success) {
                for (int i = start; i < start+size; i++) mymem[i] = id;
                answer.push_back(start);
            }
            else answer.push_back(-1);
        }
        if (type == 'F'){
            for (int i = 0 ; i < n ; i++){
                if (mymem[i] == id) mymem[i] = 1001;
            }
        }
    }
    return answer;
}
