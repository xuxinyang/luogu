#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
const int inf = INT_MAX;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
int mp[maxn][maxn], n, m, l, r, ans;
bool vis[maxn][maxn];
bool check(int v)
{
    queue<pair<int, int> > q;
    q.push(make_pair(1, 1));
    vis[1][1] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        if (x == n) return 1;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int fx = x + dx[i];
            int fy = y + dy[i];
            if (fx >= 1 && fx <= n && fy >= 1 && fy <= n
            && mp[fx][fy] <= v && !vis[fx][fy])
            {
                vis[fx][fy] = 1;
                q.push(make_pair(fx, fy));
            }
        }
    }
    return 0;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            r = max(r, mp[i][j]);
        }
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        memset(vis, 0, sizeof(vis));
        if (check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}