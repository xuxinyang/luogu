#include <iostream>
#include <queue>
using namespace std;
const int maxn = 55;
int n, m, mp[maxn][maxn], sx, sy, ex, ey;
char d;
bool vis[maxn][maxn][4];
enum DIRECTION
{
    EAST = 0,
    SOUTH = 1,
    WEST = 2,
    NORTH = 3
};
struct Node
{
    int x, y, tim, dire;
};
Node nodes[maxn * maxn];
queue<Node> q;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 1)
            {
                mp[i - 1][j] = 1;
                mp[i][j - 1] = 1;
                mp[i - 1][j - 1] = 1;
            }
        }
    }
    cin >> sx >> sy >> ex >> ey >> d;
    int f = -1;
    switch (d)
    {
    case 'E':
        f = 0;
        break;
    case 'S':
        f = 1;
        break;
    case 'W':
        f = 2;
        break;
    case 'N':
        f = 3;
        break;
    }
    q.push(Node{ sx, sy, 0, f });
    vis[sx][sy][f] = 1;
    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        if (now.x == ex && now.y == ey)
        {
            std::cout << now.tim << "\n";
            return 0;
        }
        int dire = now.dire;
        // LEFT AND RIGHT
        if (!vis[now.x][now.y][(dire - 1 + 4) % 4])
        {
            q.push(Node{ now.x, now.y, now.tim + 1, (dire - 1 + 4) % 4 });
            vis[now.x][now.y][(dire - 1 + 4) % 4] = 1;
        }
        if (!vis[now.x][now.y][(dire + 1) % 4])
        {
            q.push(Node{ now.x, now.y, now.tim + 1, (dire + 1) % 4 });
            vis[now.x][now.y][(dire + 1) % 4] = 1;
        }
        if (!vis[now.x][now.y][(dire - 2 + 4) % 4])
        {
            q.push(Node{ now.x, now.y, now.tim + 2, (dire - 2 + 4) % 4 });
            vis[now.x][now.y][(dire - 2 + 4) % 4] = 1;
        }
        // EAST
        if (dire == EAST)
        {
            int fy = now.y;
            for (int i = 1; i <= 3; i++)
            {
                if (fy + i < m && !vis[now.x][fy + i][EAST])
                {
                    if (mp[now.x][fy + i] == 1) break;
                    q.push(Node{ now.x, fy + i, now.tim + 1, EAST });
                    vis[now.x][fy + i][EAST] = 1;
                }
            }
        }
        // SOUTH
        else if (dire == SOUTH)
        {
            int fx = now.x;
            for (int i = 1; i <= 3; i++)
            {
                if (fx + i < n && !vis[fx + i][now.y][SOUTH])
                {
                    if (mp[fx + i][now.y] == 1) break;
                    q.push(Node{ fx + i, now.y, now.tim + 1, SOUTH });
                    vis[fx + i][now.y][SOUTH] = 1;
                }
            }
        }
        // WEST
        else if (dire == WEST)
        {
            int fy = now.y;
            for (int i = 1; i <= 3; i++)
            {
                if (fy - i >= 1 && !vis[now.x][fy - i][WEST])
                {
                    if (mp[now.x][fy - i] == 1) break;
                    q.push(Node{ now.x, fy - i, now.tim + 1, WEST });
                    vis[now.x][fy - i][WEST] = 1;
                }
            }
        }
        // NORTH
        else if (dire == NORTH)
        {
            int fx = now.x;
            for (int i = 1; i <= 3; i++)
            {
                if (fx - i >= 1 && !vis[fx - i][now.y][NORTH])
                {
                    if (mp[fx - i][now.y] == 1) break;
                    q.push(Node{ fx - i, now.y, now.tim + 1, NORTH });
                    vis[fx - i][now.y][NORTH] = 1;
                }
            }
        }
    }
    std::cout << -1 << "\n";
    return 0;
}