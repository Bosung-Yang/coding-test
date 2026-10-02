#include <string>
#include <vector>

using namespace std;

struct Node{
    string id;
    int best;
    int cnt;
};

bool isAhead(Node& a, Node&b){
    if (a.best != b.best) return a.best > b.best;
    if (a.cnt != b.cnt) return a.cnt < b.cnt;
    return a.id < b.id;
}

vector<string> solution(vector<string> logs, int k) {
    vector<string> answer;
    vector<Node> nodes;
    
    for (string log : logs){
        int sep = log.find(' ');
        string id = log.substr(0, sep);
        int score = stoi(log.substr(sep+1));

        int found = -1;
        for (int i = 0; i < nodes.size(); i++){
            if (nodes[i].id == id) {found = i; break;}
        }

        if (found == -1){
            nodes.push_back({id, score, 1});
        }
        else{
            nodes[found].cnt++;
            if (score > nodes[found].best) nodes[found].best = score;
        }
    }

    for (int i = 0; i < nodes.size(); i++){
        Node best = nodes[i];
        int bestidx = i;
        for (int j = i+1; j < nodes.size(); j++){
            if (!isAhead(best, nodes[j])){
                best = nodes[j];
                bestidx = j;
            }
        }
        Node temp = best;
        nodes[bestidx] = nodes[i];
        nodes[i] = temp;
    }

    
    for (int i =0 ; i < nodes.size() && i<k; i++){
        answer.push_back(nodes[i].id);
    }

    return answer;
}
