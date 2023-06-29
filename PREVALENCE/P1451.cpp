#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
int n, m, ans;
char mp[105][105];
void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int fx = x + dx[i];
        int fy = y + dy[i];
        if (fx >= 1 && fx <= n && fy >= 1 && fy <= m
        && mp[fx][fy] >= '1' && mp[fx][fy] <= '9')
        {
            mp[fx][fy] = '0';
            dfs(fx, fy);
        }
    }
    return;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] != '0')
            {
                ans++;
                mp[i][j] = '0';
                dfs(i, j);
            }
        }
    }
    cout << ans;
    return 0;
}