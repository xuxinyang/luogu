#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
int n, m, a[maxn][maxn], ans, col;
int bx, by;
int rnd1[maxn], rnd2[maxn];
bool vis[maxn][maxn];
queue<pair<int, int>> q;
map<pair<int, int>, bool> mp;
void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int fx = x + dx[i], fy = y + dy[i];
        if (fx >= 1 && fx <= n && fy >= 1 && fy <= m
        && a[fx][fy] == col && !vis[fx][fy])
        {
            q.push({fx, fy});
            vis[fx][fy] = 1;
            bx = min(bx, fx), by = min(by, fy);
            dfs(fx, fy);
        }
    }
}
void calc(int x, int y)
{
    vis[x][y] = 1, col = a[x][y], q.push({x, y});
    bx = x, by = y;
    dfs(x, y);
    int h1 = 0, h2 = 0;
    while (!q.empty())    // 对坐标进行哈希处理
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        r -= bx, c -= by;
        h1 += rnd1[r]^rnd2[c];
        h2 ^= rnd1[r]*rnd2[c];
    }
    if (!mp.count({h1, h2}))
    {
        mp[{h1, h2}] = 1, ans++;
    }
}
int main()
{
    srand(time(NULL));
    for (int i = 0; i <= 500; i++)
        rnd1[i] = rand(), rnd2[i] = rand();
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!vis[i][j]) calc(i, j);
    cout << ans;
    return 0;
}