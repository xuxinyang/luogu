#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e2+5;
int c[maxn], in[maxn], head[maxn], n, m, tot;
struct Edge
{
    int to, w, nxt;
};
Edge edges[maxn*maxn*maxn];
queue<int> q;
void add(int u, int v, int w)
{
    edges[++tot] = {v, w, head[u]};
    head[u] = tot;
}
void bfs()
{
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = edges[i].nxt)
        {
            int v = edges[i].to;
            in[v]--;
            c[v] += edges[i].w * c[u];
            if (in[v] == 0 && c[v] > 0) q.push(v);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int ui;
        cin >> c[i] >> ui;
        if (c[i] > 0) q.push(i);
        else c[i] -= ui;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        in[v]++;
    }
    bfs();
    bool flag = 0;
    for (int i = 1; i <= n; i++)
    {
        if (head[i] == 0 && c[i] > 0)
        {
            flag = 1;
            cout << i << " " << c[i] << "\n";
        }
    }
    if (!flag) cout << "NULL";
    return 0;
}