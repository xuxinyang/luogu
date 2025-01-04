#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int dis[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m, a[maxn][maxn], cnt, res;
bool vis[maxn][maxn];
priority_queue<pair<int, pair<int, int>> > pq;
void dfs(int x, int y)
{
    // cout << x << " " << y << "\n";
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dis[i][0], ny = y + dis[i][1];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny]
        && a[nx][ny] < a[x][y])
        {
            vis[nx][ny] = 1;
            if (nx == n) cnt++;
            dfs(nx, ny);
        }
    }
}
int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (i == 1) pq.push(make_pair(a[i][j], make_pair(i, j)));
        }
    }
    while (cnt < m && !pq.empty())
    {
        auto cur = pq.top();
        int x = cur.second.first, y = cur.second.second;
        if (cnt == m || pq.empty()) break;
        while (vis[x][y] && !pq.empty()) pq.pop(), cur = pq.top(), x = cur.second.first, y = cur.second.second;
        vis[x][y] = 1;
        res++;
        dfs(x, y);
    }
    if (cnt == m)
    {
        cout << "1\n";
        cout << res << "\n";
    }
    else
    {
        cout << "0\n";
        cout << m-cnt << "\n";
    }
    return 0;
}