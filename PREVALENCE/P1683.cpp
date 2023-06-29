#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
int w, h, sx, sy, ans;
char mp[25][25];
bool vis[25][25];
void dfs(int x, int y)
{
    vis[x][y] = 1;
    ans++;
    for (int i = 0; i < 4; i++)
    {
        int fx = x + dx[i];
        int fy = y + dy[i];
        if (fx >= 1 && fx <= h && fy >= 1 && fy <= w
        && mp[fx][fy] == '.' && !vis[fx][fy])
        {
            dfs(fx, fy);
        }
    }
    return;
}
int main()
{
    cin >> w >> h;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == '@') sx = i, sy = j;
        }
    }
    dfs(sx, sy);
    cout << ans;
    return 0;
}