#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int t, n, m, k, ans;
char c[maxn][maxn];
bool vis[maxn][maxn];
void dfs(int x, int y, int d)
{
    if (k-- == 0) return;
    int fx = x + dx[d], fy = y + dy[d];
    if (fx >= 1 && fx <= n && fy >= 1 && fy <= m && c[fx][fy] == '.')
    {
        if (!vis[fx][fy]) ans++;
        vis[fx][fy] = 1;
        dfs(fx, fy, d);
    }
    else d = (d+1)%4, dfs(x, y, d);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)
    {
        int x0, y0, d;
        cin >> n >> m >> k;
        cin >> x0 >> y0 >> d;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++) cin >> c[i][j];
        }
        ans = 1;
        vis[x0][y0] = 1;
        dfs(x0, y0, d);
        cout << ans << "\n";
    }
    return 0;
}