#include <string>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> T;

// 내열 등급 h로 K번 이내에 도착할 수 있는가? (온도 ≤ h 인 칸만 BFS)
bool canReach(int h, int k) {
    if (T[0][0] > h) return false;
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};

    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<int> qy, qx;          // vector 큐
    int head = 0;
    dist[0][0] = 0;
    qy.push_back(0); qx.push_back(0);

    while (head < (int)qy.size()) {
        int y = qy[head], x = qx[head];
        head++;
        if (y == n - 1 && x == m - 1) return dist[y][x] <= k;
        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d], nx = x + dx[d];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (dist[ny][nx] != -1 || T[ny][nx] > h) continue;
            dist[ny][nx] = dist[y][x] + 1;
            qy.push_back(ny); qx.push_back(nx);
        }
    }
    return false;
}

// 파라메트릭 서치 : H가 클수록 지나갈 수 있는 칸이 늘어나므로
// 결과가 "불가능 … 불가능 가능 … 가능" 모양 → 처음 가능한 H를 이분 탐색
int solution(vector<vector<int>> temp, int k) {
    T = temp;
    n = temp.size();
    m = temp[0].size();

    int lo = 1, hi = 1000000000;
    if (!canReach(hi, k)) return -1;          // 최대로 해도 안 되면 불가능

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;         // (lo + hi) / 2 는 int 오버플로 위험
        if (canReach(mid, k)) hi = mid;       // 가능 → 더 작은 H도 되는지
        else lo = mid + 1;                    // 불가능 → H를 키움
    }
    return lo;
}
