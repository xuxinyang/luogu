#include <bits/stdc++.h>
using namespace std;
int n, mp[10][10], vis[10][10], ans[10][10];
bool flag;
void down()
{
    for (int i = 1; i <= 5; i++)
    {
        int b[10] = {}, cnt = 0;
        for (int j = 1; j <= 7; j++)
        {
            if (mp[i][j]) b[++cnt] = mp[i][j];
        }
        for (int j = 1; j <= 7; j++)
        {
            mp[i][j] = b[j];
        }
    }
}
bool remove()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            if (!mp[i][j]) continue;
            if (mp[i-1][j] == mp[i][j] && mp[i+1][j] == mp[i][j])
                vis[i-1][j] = vis[i+1][j] = vis[i][j] = 1;
            if (mp[i][j-1] == mp[i][j] && mp[i][j+1] == mp[i][j])
                vis[i][j-1] = vis[i][j+1] = vis[i][j] = 1;
        }
    }
    bool ret = false;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            if (vis[i][j])
            {
                mp[i][j] = vis[i][j] = 0;
                ret = true;
            }
        }
    }
    return ret;
}
bool check()
{
    for (int i = 1; i <= 5; i++)
        if (mp[i][1]) return false;
    return true;
}
void move(int x, int y, int k)
{
    swap(mp[x][y], mp[x+k][y]);
    down();
    while (remove()) down();
}
void dfs(int x)
{
    if (flag) return;
    if (check())
    {
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i][1] << " " << ans[i][2] << " " << ans[i][3] << endl;
        }
        flag = true;
        return;
    }
    if (x > n) return;
    int tmp[10][10];
    memcpy(tmp, mp, sizeof(mp));
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            if (!mp[i][j]) break;
            if (i < 5)
            {
                ans[x][1] = i-1; ans[x][2] = j-1; ans[x][3] = 1;
                move(i, j, 1);
                dfs(x+1);
                memcpy(mp, tmp, sizeof(mp));
            }
            if (i > 1 && !mp[i-1][j])
            {
                ans[x][1] = i-1; ans[x][2] = j-1; ans[x][3] = -1;
                move(i, j, -1);
                dfs(x+1);
                memcpy(mp, tmp, sizeof(mp));

            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= 5; i++)
    {
        int p = 0, x;
        while (cin >> x && x)
        {
            mp[i][++p] = x;
        }
    }
    dfs(1);
    if (!flag) cout << -1 << endl;
    return 0;
}