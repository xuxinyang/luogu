#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int maxp = 4e4 + 5;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
// mark标记点(x,y)的四个方向是否走过了
int mark[maxn][maxn][4];
char mp[maxn][maxn];
struct Point
{
    int x, y, mir; // 坐标+镜子数量
};
queue<Point> q;
int w, h;
Point sp, ep;
bool check(Point p)
{
    return (1 <= p.x && p.x <= h && 1 <= p.y && p.y <= w && mp[p.x][p.y] != '*');
}
int bfs()
{
    q.push(sp);
    while (!q.empty())
    {
        Point cur = q.front();
        q.pop();
        cur.mir++;
        for (int i = 0; i < 4; i++)
        {
            if (mark[cur.x][cur.y][i])
                continue;
            mark[cur.x][cur.y][i] = 1;
            int fx = cur.x + dx[i], fy = cur.y + dy[i];
            int fmir = cur.mir;
            while (check(Point{fx, fy, fmir}) && !mark[fx][fy][i])
            {
                if (fx == ep.x && fy == ep.y)
                    return fmir;
                q.push(Point{fx, fy, fmir});
                mark[fx][fy][i] = 1;
                mark[fx][fy][(i + 2) % 4] = 1;
                fx += dx[i], fy += dy[i];
            }
        }
    }
    return -1;
}
int main()
{
    bool temp = 1;
    cin >> w >> h;
    memset(mark, 0, sizeof(mark));
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 'C' && temp)
            {
                sp.x = i, sp.y = j;
                sp.mir = -1, temp = 0;
            }
            else if (mp[i][j] == 'C')
            {
                ep.x = i, ep.y = j;
                ep.mir = 0;
            }
        }
    }
    ep.mir = bfs();
    cout << ep.mir;
    return 0;
}