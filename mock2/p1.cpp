#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;

    vector<vector<int>> dir = {
        {-1,-1}, // 왼쪽 위,
        {-1, 0}, // 위
        {-1,1}, 
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1,1}
    };
    int h = score.size(); int w = score[0].size();
    vector<vector<int>> beforearr(h, vector<int>(w, 3));
    //vector<vector<int>> afterarr(h, vector<int>(w, 3));
    
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            if (score[y][x] >=90) beforearr[y][x] = 3;
            else if (score[y][x] >=70 ) beforearr[y][x] = 2;
            else beforearr[y][x] = 1;
        }
    }

    vector<vector<int>> afterarr = beforearr;
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            int cnt = 0;
            for (int d = 0 ; d < 8; d++){
                int ny = y + dir[d][0];
                int nx = x + dir[d][1];
                if (ny >= 0 && nx >= 0 && ny < h && nx < w){
                    if(beforearr[ny][nx] == 1) cnt++;
                }
            }
            if (cnt >= 3 && afterarr[y][x] != 1){
                afterarr[y][x] -=1;
            }
        }
    }
    int a, b, f;
    a = b= f= 0;
    for (int i = 0 ; i < afterarr.size(); i++){
        for (int j = 0 ; j < afterarr[0].size(); j++){
            if (afterarr[i][j] == 3) a++;
            if (afterarr[i][j] == 2) b++;
            if (afterarr[i][j] == 1) f++;
        }
        
    }
    answer = {a, b, f};
    return answer;
}
