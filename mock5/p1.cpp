#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> production) {
    vector<int> answer;
    int best_line = 0;
    int best_day = 0;
    int nline = (int)production.size();
    int nday = (int)production[0].size();

    int mx_make = 0;
    for(int line = 0; line < nline; line++){
        int line_make = 0;
        for (int day = 0; day < nday; day++){
            line_make += production[line][day];
        }
        if (line_make > mx_make){
            mx_make = line_make;
            best_line = line;
        }
    }

    mx_make = 0;
    for(int day = 0; day < nday; day++){
        int day_make = 0;
        for (int line = 0; line < nline; line++){
            day_make += production[line][day];
        }
        if (day_make > mx_make){
            mx_make = day_make;
            best_day = day;
        }
    }
    
    return {best_line, best_day};
}
