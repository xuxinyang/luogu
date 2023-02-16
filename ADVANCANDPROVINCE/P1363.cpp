#include <bits/stdc++.h>
using namespace std;
const int maxn = 1505;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, m, sx, sy;
int vis[maxn][maxn][3];
bool flag, a[maxn][maxn];
char ch;
void dfs(int x, int y, int lx, int ly)
{
    if (flag) return;
    if (vis[x][y][0] && (vis[x][y][1] != lx || vis[x][y][2] != ly))
    {
        flag = 1;
        return;
    }
    vis[x][y][1] = lx, vis[x][y][2] = ly, vis[x][y][0] = 1;
    for (int i = 0; i < 4; i++)
    {
        int fx = (x + dx[i] + n) % n, fy = (y + dy[i] + m) % m;
        int lxx = lx + dx[i], lyy = ly + dy[i];
        if (!a[fx][fy])
        {
            if (vis[fx][fy][1] != lxx || vis[fx][fy][2] != lyy || !vis[fx][fy][0])
                dfs(fx, fy, lxx, lyy);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m)
    {
        flag = 0;
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> ch;
                if (ch == '#') a[i][j] = 1;
                if (ch == 'S') sx = i, sy = j;
            }
        }
        dfs(sx, sy, sx, sy);
        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}