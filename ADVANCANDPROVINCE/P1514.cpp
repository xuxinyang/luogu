#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int dis[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m, a[maxn][maxn], ans;
bool vis[maxn][maxn];
int l[maxn][maxn], r[maxn][maxn];
void dfs(int x, int y)
{
    // cout << x << " " << y << "\n";
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dis[i][0], ny = y + dis[i][1];
        if (nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] >= a[x][y]) continue; 
        if (!vis[nx][ny]) dfs(nx, ny);
        l[x][y] = min(l[x][y], l[nx][ny]);
        r[x][y] = max(r[x][y], r[nx][ny]);
    }
}
int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    cin >> n >> m;
    memset(l, 0x3f, sizeof(l));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (i == n) l[i][j] = r[i][j] = j;
        }
    }
    for (int i = 1; i <= m; i++) if (!vis[1][i]) dfs(1, i);
    int f = 1;
    for (int i = 1; i <= m; i++) if (!vis[n][i]) ans++, f = 0;
    if (!f) {cout << "0\n" << ans << "\n"; return 0;}
    int le = 1, ri = r[1][1];
    while (le <= m)
    {
        for (int i = 1; i <= m; i++)
        {
            if (l[1][i] <= le) ri = max(ri, r[1][i]);
        }
        le = ri+1;
        ans++;
    }
    cout << "1\n" << ans << "\n";
    return 0;
}