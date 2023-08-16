#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
struct Edge
{
    int to, next, from;
};
Edge edges[maxn << 2];
int n, m, top, tot, s, p[maxn];
int head[maxn], in[maxn], dist[maxn];
int dfn[maxn], low[maxn], p[maxn];
stack<int> st;
void add(int u, int v)
{
    edges[++tot] = Edge{v, head[u], u};
    head[u] = tot;
}
void tarjan(int u)
{

}
int topo()
{

}
int main()
{
    int u, v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        add(u, v);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= m; i++)
    {
        
    }
    return 0;
}