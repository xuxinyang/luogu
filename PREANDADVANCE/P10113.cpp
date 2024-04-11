#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, q, m;
int fa[maxn][30], mx[maxn], dep[maxn], lc[maxn];
vector<int> ve[maxn];
void dfs(int x, int f, int maxx)
{
    if (x > maxx) maxx = x;
    mx[x] = maxx, dep[x] = dep[f] + 1;
    if (x != 0)
    {
        fa[x][0] = f;
        for (int i = 1; i <= lc[dep[x]]; i++)
        {
            fa[x][i] = fa[fa[x][i-1]][i-1];
        }
    }
    for (int i = 0; i < ve[x].size(); i++)  dfs(ve[x][i], x, maxx);
}
int lca(int a, int b)
{
    if (dep[a] < dep[b]) swap(a, b);
    while (dep[a] > dep[b])
        a = fa[a][lc[dep[a]-dep[b]]];
    if (a == b) return a;
    for (int i = lc[dep[a]]; i >= 0; i--)
    {
        if (fa[a][i] != fa[b][i]) a = fa[a][i], b = fa[b][i];
    }
    return fa[a][0];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, lcaa;
    cin >> n;
    lc[0] = -1;
    for (int i = 1; i < n; i++)
    {
        lc[i] = lc[i>>1]+1;
        cin >> x;
        ve[x].push_back(i);
    }
    dfs(0, 0, 0);
    cin >> q;
    while (q--)
    {
        cin >> m >> lcaa;
        while (--m)
        {
            cin >> x;
            lcaa = lca(lcaa, x);
        }
        cout << mx[lcaa] << "\n";
    }
    return 0;
}