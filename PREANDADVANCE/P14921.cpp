#include <bits/stdc++.h>
using namespace std;
const int N = 2e3+5;
int n, m, dist[N];
vector<int> ve[N];
void bfs(int u)
{
    queue<int> q;
    memset(dist, 0x3f, sizeof dist);
    q.push(u);
    dist[u] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto v : ve[cur])
        {
            if (dist[cur]+1 < dist[v])
            {
                dist[v] = dist[cur]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        ve[u].push_back(v), ve[v].push_back(u);
    }
    int minx = 1e9, idx = 1;
    for (int i = 1; i <= n; i++)
    {
        bfs(i);
        int maxx = 0;
        for (int j = 1; j <= n; j++) maxx = max(maxx, dist[j]);
        if (minx > maxx)
        {
            minx = maxx;
            idx = i;
        }
    }
    cout << idx;
    return 0;
}