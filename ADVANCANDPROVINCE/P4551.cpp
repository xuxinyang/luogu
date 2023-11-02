#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, m, head[maxn], tot, sum[maxn], ans;
struct Edge
{
    int to, w, nxt;
};
Edge edges[maxn<<1];
struct Trie
{
    int ch[2];
};
Trie tries[maxn<<4];
void add(int u, int v, int w)
{
    edges[++tot] = Edge{v, w, head[u]};
    head[u] = tot;
}
void dfs(int x, int fa)
{
    for (int i = head[x]; ~i; i = edges[i].nxt)
    {
        int v = edges[i].to;
        int w = edges[i].w;
        if (v != fa)
        {
            sum[v] = sum[x] ^ w;
            dfs(v, x);
        }
    }
}
void build(int val, int x)
{
    for (int i = (1 << 30); i; i >>= 1)
    {
        bool c = val & i;
        if (!tries[x].ch[c]) tries[x].ch[c] = ++tot;
        x = tries[x].ch[c];
    }
}
int query(int val, int x)
{
    int ans = 0;
    for (int i = (1 << 30); i ; i >>=1)
    {
        bool c = val & i;
        if (tries[x].ch[!c]) ans += i, x = tries[x].ch[!c];
        else x = tries[x].ch[c];
    }
    return ans;
}
int main()
{
    int u, v, w;
    cin >> n;
    m = n - 1;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++) build(sum[i], 0);
    for (int i = 1; i <= n; i++)
        ans = max(ans, query(sum[i], 0));
    cout << ans;
    return 0;
}