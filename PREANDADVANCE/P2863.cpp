#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
vector<int> g[maxn];
stack<int> st;
int n, m, dfn[maxn], low[maxn], used[maxn], vis[maxn], color[maxn], num[maxn], colorid, tot, ans;
void dye(int x)
{
    st.pop();
    color[x] = colorid;
    num[colorid]++;
    vis[x] = false;
}
void tarjan(int u)
{
    dfn[u] = low[u] = ++tot;
    st.push(u);
    vis[u] = used[u] = true;
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (vis[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        colorid++;
        while (st.top() != u) dye(st.top());
        dye(u);
    }
}
int main()
{
    int u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!used[i]) tarjan(i);
    }
    for (int i = 1; i <= colorid; i++)
        if (num[i] > 1) ans++;
    cout << ans;
    return 0;
}