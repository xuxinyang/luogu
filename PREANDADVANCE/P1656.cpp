#include <bits/stdc++.h>
using namespace std;
const int maxn = 155;
const int maxm = 5005;
struct Edge
{
    int to, nxt;
};
int n, m, u, v, head[maxn], tot;
Edge edges[maxm];

void add(int u, int v)
{
    edges[++tot].to = v;
    edges[tot].nxt = head[u];
    head[u] = tot;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    
    return 0;
}