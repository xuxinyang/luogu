#include <bits/stdc++.h>
using namespace std;
int n, sx, sy, ex, ey;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
char mp[1005][1005];
bool vis[1005][1005];
struct Node
{
    int x, y, step;
};
queue<Node> q;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mp[i][j];
        }
    }
    cin >> sx >> sy >> ex >> ey;
    q.push((Node){sx, sy, 0});
    vis[sx][sy] = 1;
    while (!q.empty())
    {
        Node node = q.front();
        q.pop();
        if (node.x == ex && node.y == ey)
        {
            cout << node.step << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int fx = node.x + dx[i];
            int fy = node.y + dy[i];
            if (fx >= 1 && fx <= n && fy >= 1 && fy <= n
             && mp[fx][fy] == '0' && vis[fx][fy] == 0)
            {
                q.push((Node){fx, fy, node.step+1});
                vis[fx][fy] = 1;
            }

        }
    }
    return 0;
}