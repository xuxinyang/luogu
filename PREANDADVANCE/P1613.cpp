#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
#define ll long long
ll n, m, u, v, a[maxn][maxn][65];
ll f[maxn][maxn], dis[maxn];
bool vis[maxn];

void spfa(int s)
{
    queue<int> q;
    memset(dis, 0x3f, sizeof(dis[0])*(n+1));
    q.push(s);
    dis[s] = 0;
    vis[s] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        vis[cur] = 0;
        for (int v = 1; v <= n; v++)
        {
            if (f[cur][v] && dis[v] > dis[cur] + f[cur][v])
            {
                dis[v] = dis[cur] + f[cur][v];
                if (vis[v] == 0)
                    vis[v] = 1, q.push(v);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        a[u][v][0] = 1;
    }
    for (int k = 1; k <= 64; k++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int u = 1; u <= n; u++)
            {
                for (int v = 1; v <= n; v++)
                {
                    if (a[u][j][k-1] && a[j][v][k-1]) a[u][v][k] = 1;
                }
            }
        }
    }
    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= n; v++)
        {
            for (int k = 0; k <= 64; k++)
            {
                if (a[u][v][k])
                {
                    f[u][v] = 1;
                    break;
                }
            }
        }
    }
    spfa(1);
    cout << dis[n] << endl;
    return 0;
}