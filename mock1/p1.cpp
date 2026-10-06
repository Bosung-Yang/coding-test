#include <string>
#include <vector>

using namespace std;

struct Equipment {
    string id;
    int total;   // 총 가동 시간(분)
};

// "HH:MM" → 분
int toMinutes(const string& t) {
    return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
}

// a가 b보다 앞 순위면 true (가동 시간 긴 순 → ID 사전순)
bool isAhead(const Equipment& a, const Equipment& b) {
    if (a.total != b.total) return a.total > b.total;
    return a.id < b.id;
}

vector<string> solution(vector<string> logs) {
    vector<Equipment> equips;

    // 핵심 : 가동 시간 = Σ(OFF - ON) = ΣOFF - ΣON
    // → 로그가 섞여 있어도 시간순 정렬 없이 OFF는 더하고 ON은 빼면 됨
    for (const string& log : logs) {
        int sp1 = log.find(' ');
        int sp2 = log.find(' ', sp1 + 1);
        string id = log.substr(0, sp1);
        int minutes = toMinutes(log.substr(sp1 + 1, sp2 - sp1 - 1));
        string state = log.substr(sp2 + 1);

        // 장비 찾기 (map 대신 선형 탐색)
        int idx = -1;
        for (int i = 0; i < (int)equips.size(); i++) {
            if (equips[i].id == id) { idx = i; break; }
        }
        if (idx == -1) {
            equips.push_back({id, 0});
            idx = equips.size() - 1;
        }

        if (state == "OFF") equips[idx].total += minutes;
        else equips[idx].total -= minutes;
    }

    // 삽입 정렬
    for (int i = 1; i < (int)equips.size(); i++) {
        Equipment cur = equips[i];
        int j = i - 1;
        while (j >= 0 && isAhead(cur, equips[j])) {
            equips[j + 1] = equips[j];
            j--;
        }
        equips[j + 1] = cur;
    }

    vector<string> answer;
    for (const Equipment& e : equips) answer.push_back(e.id);
    return answer;
}
