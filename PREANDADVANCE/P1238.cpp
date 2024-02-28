#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
int m, n, a[20][20], sx, sy, ex, ey, p;
bool vis[20][20], flag;
struct Node
{
    int x, y;
};
Node path[400];
void dfs(int x, int y)
{
    if (x == ex && y == ey)
    {
        flag = 1;
        printf("(%d,%d)", sx, sy);
        for (int i = 2; i <= p; i++)
        {
            printf("->(%d,%d)", path[i].x, path[i].y);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int fx = x + dx[i], fy = y + dy[i];
        if (fx >= 1 && fx <= m && fy >= 1 && fy <= n && a[fx][fy] == 1 && !vis[fx][fy])
        {
            path[++p] = {fx, fy};
            vis[fx][fy] = 1;
            dfs(fx, fy);
            vis[fx][fy] = 0;
            p--;
        }
    }
}
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> sx >> sy >> ex >> ey;
    path[++p] = {sx, sy};
    vis[sx][sy] = 1;
    dfs(sx, sy);
    if (!flag) cout << -1;
    return 0;
}