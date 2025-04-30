#include <bits/stdc++.h>
using namespace std;

const int N = 1505;
const int INF = 0x3f3f3f3f;
const int dx[4] = {1, 1, -1, -1}; // ↘ ↙ ↖ ↗
const int dy[4] = {1, -1, 1, -1};

int n, sx, sy, ex, ey;
int d[N][N][4];
char c[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> sx >> sy >> ex >> ey;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    // 奇偶剪枝
    if ((sx + sy) % 2 != (ex + ey) % 2) {
        cout << -1 << '\n';
        return 0;
    }
    memset(d, 0x3f, sizeof(d));
    deque<array<int, 3>> dq;
    for (int dir = 0; dir < 4; dir++) {
        d[sx][sy][dir] = 0;
        dq.push_back({sx, sy, dir});
    }
    while (!dq.empty()) {
        auto [x, y, dir] = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > n || c[nx][ny] != '.') continue;
            int cost = d[x][y][dir] + (dir != i);
            if (cost < d[nx][ny][i]) {
                d[nx][ny][i] = cost;
                if (dir == i)
                    dq.push_front({nx, ny, i});
                else
                    dq.push_back({nx, ny, i});
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < 4; i++)
        ans = min(ans, d[ex][ey][i]);

    cout << (ans == INF ? -1 : ans+1) << '\n';
    return 0;
}
