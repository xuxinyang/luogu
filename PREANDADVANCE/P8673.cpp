#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int maxn = 1e3+5;
int n, k;
char c[maxn][maxn];
int vis[maxn][maxn];
queue<array<int, 4>> q;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) cin >> c[i][j];
    }
    memset(vis, -1, sizeof vis);
    vis[1][1] = 0;
    q.push({1, 1, 0, 0});
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        if (cur[0] == n && cur[1] == n)
        {
            cout << cur[2] << "\n";
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int x = cur[0] + dx[i], y = cur[1] + dy[i];
            int step = cur[2], sta = cur[3];
            if (x > n || x < 1 || y > n || y < 1 || c[x][y] == '#') continue;
            if (c[x][y] == 'X' && sta == 0) continue;
            sta = max(0, sta-1);
            if (c[x][y] == '%') sta = k;
            if (vis[x][y] < sta) vis[x][y] = sta, q.push({x, y, step+1, sta});
        }
    }
    cout << "-1\n";
    return 0;
}