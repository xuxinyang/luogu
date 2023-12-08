#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int inf = 0x3f3f3f3f;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
int n, m, a[maxn][maxn], minx = inf, maxx, ans, t, sx, sy;
bool f[maxn][maxn];
bool vis[maxn][maxn];
struct Node
{
    int x, y;
};
bool check(int d)
{
    queue<Node> q;
    memset(vis, 0, sizeof(vis));
    int sum = 0;
    q.push(Node{sx, sy});
    vis[sx][sy] = 1;
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        if (f[cur.x][cur.y]) sum++;
        for (int i = 0; i < 4; i++)
        {
            int fx = cur.x + dx[i];
            int fy = cur.y + dy[i];
            if (fx >= 1 && fx <= n && fy >= 1 && fy <= m && abs(a[fx][fy] - a[cur.x][cur.y]) <= d && !vis[fx][fy])
            {
                vis[fx][fy] = 1;
                q.push(Node{fx, fy});
            }
        }
    }

    return sum == t;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            maxx = max(a[i][j], maxx);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> f[i][j];
            if (f[i][j]) sx = i, sy = j, t++;
        }
    }
    int l = 0, r = maxx;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}