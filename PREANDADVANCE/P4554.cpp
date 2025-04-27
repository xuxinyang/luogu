#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int maxn = 505;
int n, m, sx, sy, ex, ey, d[maxn][maxn];;
char c[maxn][maxn];
bool vis[maxn][maxn];
struct Node
{
    int x, y;
};
void bfs()
{
    d[sx][sy] = 0;
    deque<Node> dq;
    dq.push_front({sx, sy});
    while (!dq.empty())
    {
        auto cur = dq.front(); dq.pop_front();
        if (vis[cur.x][cur.y]) continue;
        vis[cur.x][cur.y] = 1;
        // cout << cur.x << " " << cur.y << "\n";
        for (int i = 0; i < 4; i++)
        {
            int fx = cur.x + dx[i], fy = cur.y + dy[i];
            if (fx < 1 || fx > n || fy < 1 || fy > m) continue;
            int w = (c[cur.x][cur.y] != c[fx][fy]);
            if (d[cur.x][cur.y] + w >= d[fx][fy]) continue;
            d[fx][fy] = d[cur.x][cur.y] + w;
            if (w == 0) dq.push_front({fx, fy});
            else dq.push_back({fx, fy});
            
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0) break;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++) cin >> c[i][j];
        }
        cin >> sx >> sy >> ex >> ey;
        sx += 1, sy += 1, ex += 1, ey += 1;
        memset(d, 0x3f, sizeof(d));
        memset(vis, 0, sizeof(vis));
        bfs();
        cout << d[ex][ey] << "\n";
    }
    return 0;
}