#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int r, c, ans;
char mp[1005][1005];
void dfs(int x, int y)
{
    mp[x][y] = '.';
    for (int i = 0; i < 4; i++)
    {
        int fx = x + dx[i];
        int fy = y + dy[i];
        if (fx >= 1 && fx <= r && fy >= 1 && fy <= c &&
            mp[fx][fy] == '#')
        {
            dfs(fx, fy);
        }
    }
}
int main()
{
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            int tmp = 0;
            if (mp[i][j] == '#') tmp++;
            if (mp[i][j+1] == '#') tmp++;
            if (mp[i+1][j] == '#') tmp++;
            if (mp[i+1][j+1] == '#') tmp++;
            if (tmp == 3)
            {
                cout << "Bad placement.";
                return 0;
            }
        }
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (mp[i][j] == '#')
            {
                ans++;
                dfs(i, j);
            }
        }
    }
    printf("There are %d ships.", ans);
    return 0;
}