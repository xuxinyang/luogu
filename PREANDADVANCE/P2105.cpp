#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4+5;
bool vis[maxn][maxn];
int n, m, k, x, y, ans, p;
struct Pos
{
    int x, y;
};
Pos pos[505];
bool check(int x, int y)
{
    for (int i = 1; i <= p; i++)
    {
        if (pos[i].x == x && pos[i].y == y)
            return true;
    }
    return false;
}
int main()
{
    cin >> n >> m >> k;
    ans = n * m;
    int x1, y1;
    for (int i = 1; i <= k; i++)
    {
        cin >> x >> y;
        pos[++p] = Pos{x, y};
        if (!vis[x][y])
        {
            ans--;
            vis[x][y] = 1;
        }
        // up
        x1 = x-1, y1 = y;
        while (x1 >= 1)
        {
            if (!vis[x1][y1])
            {
                ans--;
                vis[x1][y1] = 1;
            }
            x1--;
        }
        // down
        x1 = x+1, y1 = y;
        while (x1 <= n)
        {
            if (check(x1, y1)) break;
            if (!vis[x1][y1])
            {
                ans--;
                vis[x1][y1] = 1;
            }
            x1++;
        }
        // left
        x1 = x, y1 = y-1;
        while (y1 >= 1)
        {
            if (check(x1, y1)) break;
            if (!vis[x1][y1])
            {
                ans--;
                vis[x1][y1] = 1;
            }
            y1--;
        }
        // right
        x1 = x, y1 = y+1;
        while (y1 <= m)
        {
            if (check(x1, y1)) break;
            if (!vis[x1][y1])
            {
                ans--;
                vis[x1][y1] = 1;
            }
            y1++;
        }
        // lu
        x1 = x-1, y1 = y-1;
        while (y1 >= 1 && x1 >= 1)
        {
            if (check(x1, y1)) break;
            if (!vis[x1][y1])
            {
                ans--;
                vis[x1][y1] = 1;
            }
            y1--, x1--;
        }
        // ru
        x1 = x-1, y1 = y+1;
        while (y1 <= m && x1 >= 1)
        {
            if (check(x1, y1)) break;
            if (!vis[x1][y1])
            {
                ans--;
                vis[x1][y1] = 1;
            }
            y1++, x1--;
        }
        // ld
        x1 = x+1, y1 = y-1;
        while (y1 >= 1 && x1 <= n)
        {
            if (check(x1, y1)) break;
            if (!vis[x1][y1])
            {
                ans--;
                vis[x1][y1] = 1;
            }
            y1--, x1++;
        }
        // rd
        x1 = x+1, y1 = y+1;
        while (y1 <= m && x1 <= n)
        {
            if (check(x1, y1)) break;
            if (!vis[x1][y1])
            {
                ans--;
                vis[x1][y1] = 1;
            }
            y1++, x1++;
        }
    }
    cout << ans;
    return 0;
}