#include <bits/stdc++.h>
using namespace std;
char c[105][105];
int n, m, ans;
void dfs(int x, int y)
{
    for (int i = max(1, x-2); i <= min(n, x+2); i++)
    {
        for (int j = max(1, y-2); j <= min(m, y+2); j++)
        {
            if (abs(x-i)+abs(y-j) <= 2)
            {
                int fx = i, fy = j;
                if (c[fx][fy] == '#')
                {
                    c[i][j] = '-';
                    dfs(fx, fy);
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (c[i][j] == '#')
            {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans;
    return 0;
}