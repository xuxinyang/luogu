#include <bits/stdc++.h>
using namespace std;
int t, n, m, a[10][10], ans, vis[10][10];
const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
void dfs(int x, int y, int sum)
{
    if (x > n)
    {
        ans = max(ans, sum);
        return;
    }
    int fx = x, fy = y + 1;
    if (fy > m) fy = 1, fx = x + 1;
    bool flag = 1;
    for (int i = 0; i < 8; i++) flag &= (!vis[x+dx[i]][y+dy[i]]);
    if (flag)
    {
        vis[x][y] = 1;
        dfs(fx, fy, sum + a[x][y]);
        vis[x][y] = 0;
    }
    dfs(fx, fy, sum);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        ans = 0;
        memset(vis, 0, sizeof(vis));
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        dfs(1, 0, 0);
        cout << ans << "\n";
    }
    return 0;
}