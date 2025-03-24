#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
char c[N][N];
int vis[N][N];
int n, m, cnt, mk;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == '#')
            {
                vis[i][j]++;
                vis[i+1][j]++;
                vis[i][j+1]++;
                vis[i-1][j]++;
                vis[i][j-1]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int s = 0;
            if (vis[i][j] == 0) cnt++;
            else if (c[i][j]=='#')
            {
                if (i+1 <= n && vis[i+1][j] == 1) s++;
                if (j+1 <= m && vis[i][j+1] == 1) s++;
                if (i-1 >= 1 && vis[i-1][j] == 1) s++;
                if (j-1 >= 1 && vis[i][j-1] == 1) s++;
                if (vis[i][j] == 1) s++;
            }
            mk = max(mk, s);
        }
    }
    cout << cnt+mk;
    return 0;
}