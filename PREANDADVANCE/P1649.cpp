#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
int n, sx, sy, ex, ey, dis[105][105];
char c[105][105];
queue<array<int, 2>> q;
bool check(int fx, int fy)
{
    return !(fx < 1 || fx > n || fy < 1 || fy > n || c[fx][fy] == 'x');
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == 'A') sx = i, sy = j;
            if (c[i][j] == 'B') ex = i, ey = j;
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[sx][sy] = 0;
    q.push({sx, sy});
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        // cout << cur[0] << " " << cur[1] << "\n";
        if (cur[0] == ex && cur[1] == ey) break;
        for (int i = 0; i < 4; i++)
        {
            int fx = cur[0] + dx[i], fy = cur[1] + dy[i];
            while (check(fx, fy))
            {
                if (dis[fx][fy] > dis[cur[0]][cur[1]]+1)
                {
                    dis[fx][fy] = dis[cur[0]][cur[1]] + 1;
                    q.push({fx, fy});
                }
                fx += dx[i], fy += dy[i]; 
            }
        }
    }
    if (dis[ex][ey] == inf) cout << -1;
    else cout << dis[ex][ey]-1;
    return 0;
}