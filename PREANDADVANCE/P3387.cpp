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
int dfn[maxn], low[maxn], p[maxn], tim;
bool vis[maxn];
stack<int> st;
void add(int u, int v)
{
    edges[++tot] = Edge{v, head[u], u};
    head[u] = tot;
}
void tarjan(int u)
{
    low[u] = dfn[u] = ++tim;
    st.push(u), vis[u] = 1;
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (vis[v])
        {
            low[u] = min(low[u], low[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        
    }
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