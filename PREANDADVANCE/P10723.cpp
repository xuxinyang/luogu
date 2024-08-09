#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, a[maxn], cntz, cntc, start, vis[maxn];
vector<int> ve[maxn];
void add(int u, int v)
{
    ve[u].push_back(v);
}
void dfs(int u)
{
    vis[u] = 1;
    for (int i = 0; i < ve[u].size(); i++)
    {
        int v = ve[u][i];
        if (!vis[v])
        {
            if (ve[v].size() == 1 && a[v] == 0) cntc++;
            dfs(v);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0) cntz++;
        if (a[i] == 1) start = i;
    }
    int u, v;
    for (int i = 1; i <= n-1; i++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(start);
    cout << cntz - cntc;
    return 0;
}