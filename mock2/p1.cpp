#include <string>
#include <vector>

using namespace std;

// 등급 번호 : 0 = A, 1 = B, 2 = F
const int A = 0, B = 1, F = 2;

vector<int> solution(vector<vector<int>> score) {
    int h = score.size(), w = score[0].size();

    // 1. 기본 등급
    vector<vector<int>> base(h, vector<int>(w));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (score[y][x] >= 90) base[y][x] = A;
            else if (score[y][x] >= 70) base[y][x] = B;
            else base[y][x] = F;
        }
    }

    // 2. 강등 판정은 모두 "기본 등급"으로 (동시 판정)
    //    결과를 base에 바로 덮어쓰면 다른 칸 판정에 영향을 주므로 따로 셈
    vector<int> count(3, 0);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int fCount = 0;   // 주변 8칸의 기본 등급 F 개수
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dy == 0 && dx == 0) continue;
                    int ny = y + dy, nx = x + dx;
                    if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                    if (base[ny][nx] == F) fCount++;
                }
            }
            int grade = base[y][x];
            if (fCount >= 3 && grade != F) grade++;   // 한 단계 강등 (F는 그대로)
            count[grade]++;
        }
    }
    return count;   // [A 개수, B 개수, F 개수]
}
