#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int x, y, mx, my, ans;
char mp[105][105];
struct Pos
{
    int x, y, step;
};
queue<Pos> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> y >> x >> my >> mx;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= y; j++)
        {
            cin >> mp[i][j];
        }
    }  
    mx = x + 1 - mx;
    mp[mx][my] = '*';
    q.push(Pos{mx, my, 0});
    while (!q.empty())
    {
        Pos cur = q.front();
        q.pop();
        ans = max(ans, cur.step);
        for (int i = 0; i < 8; i++)
        {
            int fx = cur.x + dx[i];
            int fy = cur.y + dy[i];
            if (fx >= 1 && fx <= x && fy >= 1 && fy <= y && mp[fx][fy] == '.')
            {
                mp[fx][fy] = '*';
                q.push(Pos{fx, fy, cur.step + 1});
            }
        }
    }
    cout << ans;
    return 0;
}