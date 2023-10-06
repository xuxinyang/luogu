#include <bits/stdc++.h>
using namespace std;
char a[15][15];
int n, ans;
bool vis[15][15];
bool check(int x, int y)
{
    if (a[x][y] == '.') return false;
    for (int i = 1; i < x; i++)
        if (vis[i][y]) return false;
    for (int i = 1; i <= min(x, y); i++)
        if (vis[x-i][y-i]) return false;
    for (int i = min(x, n-y); i >= 1; i--)
        if (vis[x-i][y+i]) return false;
    return true;
}
void dfs(int x)
{
    if (x == n + 1)
    {
        ans++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (check(x, i))
        {
            vis[x][i] = 1;
            dfs(x+1);
            vis[x][i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    dfs(1);
    cout << ans;
    return 0;
}