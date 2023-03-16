#include <bits/stdc++.h>
using namespace std;
int t, n, mp[1005][1005];
bool vis[1005][1005];
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
struct Node
{
    int x, y;
};
bool bfs()
{
    queue<Node> p, q;
    memset(mp, 0, sizeof(mp));
    memset(vis, 0, sizeof(vis));
    q.push((Node){1, 1});
    vis[1][1] = 1;
    cin >> n;
    for (int i = 1; i <= 2 * n - 2; i++)
    {
        int x, y;
        cin >> x >> y;
        p.push((Node){x, y});
    }
    while (!q.empty())
    {
        Node node = q.front();
        q.pop();
        if (node.x == n && node.y == n)
            return true;
        for (int i = 0; i < 4; i++)
        {
            int fx = node.x + dx[i];
            int fy = node.y + dy[i];
            if (fx >= 1 && fx <= n && fy >= 1 && fy <= n
            && mp[fx][fy] == 0 && vis[fx][fy] == 0)
            {
                q.push((Node){fx, fy});
                vis[fx][fy] = 1;
            }
        }
        if (p.size())
        {
            Node stone = p.front();
            p.pop();
            mp[stone.x][stone.y] = 1;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        if (bfs()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}