#include <bits/stdc++.h>
using namespace std;
int mp[11][11], n, a[205], t;
bool v[205], s[105];
void dfs(int x, int y)
{
    if (x == n+1 && y == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << mp[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }
    if (x == 1 || y == 1)
    {
        for (int i = 2; i <= n*n; i++)
        {
            if (s[i]) continue;
            if ((x==1&&y!=1&&!v[i+mp[x][y-1]])||(x!=1&&y==1&&!v[i+mp[x-1][y]])
            || (x!=1&&y!=1&&!v[i+mp[x-1][y]] && !v[i+mp[x][y-1]]))   // 上下左右的和是否为素数
            {
                mp[x][y] = i, s[i] = 1;
                if (y == n) dfs(x+1, 1);
                else dfs(x, y+1);
                mp[x][y] = 0; s[i] = 0;
            }
        }
    }
    else
    {
        for (int i = n*n; i >= 2; i--)
        {
            if (s[i]) continue;
            if ((x==1&&y!=1&&!v[i+mp[x][y-1]])||(x!=1&&y==1&&!v[i+mp[x-1][y]])
            || (x!=1&&y!=1&&!v[i+mp[x-1][y]]&&!v[i+mp[x][y-1]]))
            {
                mp[x][y] = i, s[i] = 1;
                if (y == n) dfs(x+1, 1);
                else dfs(x, y+1);
                mp[x][y] = 0, s[i] = 0;
            }
        }
    }
}
int main()
{
    cin >> n;
    if (n == 1)
    {
        cout << "NO";
        return 0;
    }
    for (int i = 2; i <= n*n*2; i++)
    {
        if (!v[i]) a[++t] = i;
        for (int j = 1; j <= t; j++)
        {
            if (i*a[j]>200) break;
            v[i*a[j]] = 1;
            if (i%a[j] == 0) break;
        }
    }
    mp[1][1] = 1, s[1] = 1;
    dfs(1, 2);
    cout << "NO";
    return 0;
}