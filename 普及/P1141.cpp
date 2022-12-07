#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int maxm = 1e3+5;
int n, m, ans[maxn], f[maxm][maxm];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool a[maxm][maxm];
void dfs(int r, int c, int flag, int k)
{
    if (r < 1 || r > n || c < 1 || c > n || f[r][c] != -1 || a[r][c] != flag) return;
    f[r][c] = k, ans[k]++;
    for (int i = 0; i < 4; i++) dfs(r + dx[i], c + dy[i], !flag, k);

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    memset(f, -1, sizeof(f));
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        if (f[x][y] == -1) dfs(x, y, a[x][y], i);
        else ans[i] = ans[f[x][y]];
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << "\n";
    return 0;
}