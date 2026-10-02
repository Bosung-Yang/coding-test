#include <string>
#include <vector>
#include <stack>
use namespace std;

string solution(string init, vector<string> commands){
    int cursor = init.size();
    string answer = init;
    stack<string> st;
    for (string command : commands){
        if (command == "L"){
            cursor -= 1;
            if (cursor < 0) cursor = 0;
        }
        if (command == "R"){
            cursor +=1;
            if (cursor >= commands.size()) cursor = commands.size()
        }
        if (command[0] = 'P'){
            string fronts = answer.substr(0,cursor);
            string ends = answer.substr(cursor, answer.end());
            // abc
            answer = fronts + command[3] + ends;
            st.push(command);
        }
        if (command == "B"){
            string fronts = answer.substr(0,cursor-1);
            string ends = answer.substr(cursor, answer.size());
            answer = fronts + ends;
            st.push(command);
        }
        if (command == "U"){
            string st_command = st.top(); st.pop();
            if st_command[]
        }

    }
}