#include <bits/stdc++.h>
using namespace std;
bool vis[20][20];
int h, w, a, b, cnt;
void dfs(int x, int y)
{
    if (x > h)
    {
        cnt++;
        return ;
    }
    if (y > w) dfs(x+1, 1);
    if (vis[x][y]) dfs(x, y+1);
    if (a)
    {
        a--;
        if (y+1 <= w && !vis[x][y+1])
        {
            vis[x][y+1] = 1;
            dfs(x, y+2);
            vis[x][y+1] = 0;
        }
        if (x+1 <= h && !vis[x+1][y])
        {
            vis[x+1][y] = 1;
            dfs(x, y+1);
            vis[x+1][y] = 0;
        }
        a++;
    }
    if (b)
    {
        b--;
        dfs(x, y+1);
        b++;
    }
}
int main()
{
    cin >> h >> w >> a >> b;
    dfs(1, 1);
    cout << cnt;
    return 0;
}