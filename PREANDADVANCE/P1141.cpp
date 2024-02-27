#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
const int maxm = 1e5+5;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
int n, m, sx, sy, ans[maxm], f[maxn][maxn];
bool a[maxn][maxn];
void dfs(int x, int y, bool flag, int k)
{
    for (int i = 0; i < 4; i++)
    {
        int fx = x + dx[i], fy = y + dy[i];
        if (fx < 1 || fx > n || fy < 1 || fy > n) continue;
        if (a[fx][fy] == !flag && f[fx][fy] == -1)
        {
            f[fx][fy] = k;
            ans[k]++;
            dfs(fx, fy, !flag, k);
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    memset(f, -1, sizeof(f));
    for (int i = 1; i <= m; i++)
    {
        cin >> sx >> sy;
        if (f[sx][sy] == -1)
        {
            f[sx][sy] = i;
            ans[i]++;
            dfs(sx, sy, a[sx][sy], i);
        }
        else ans[i] = ans[f[sx][sy]];
        cout << ans[i] << "\n";
    }
    return 0;
}