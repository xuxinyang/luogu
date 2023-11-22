#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int t, n, k, head[maxn], tot, st[maxn], cnt;
struct Edge
{
    int to, next;
};
Edge edges[maxn<<1];
void add(int u, int v)
{
    edges[++tot] = Edge{v, head[u]};
    head[u] = tot;
}
void dfs(int u, int s)
{
    st[u] = 1;
    for (int i = head[u]; i; i = edges[i].next)
    {
        int to = edges[i].to;
        if (to == s) continue;
        dfs(to, u);
        st[u] += st[to];
    }
    if (st[u] == k)
    {
        st[u] = 0;
        cnt++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int u, v;
    cin >> t;
    while (t--)
    {
        memset(head, 0, sizeof(head));
        memset(st, 0, sizeof(st));
        tot = 0, cnt = 0;
        memset(edges, 0, sizeof(edges));
        cin >> n >> k;
        for (int i = 1; i <= n-1; i++)
        {
            cin >> u >> v;
            add(u, v);
            add(v, u);
        }
        if (n % k != 0)
        {
            cout << "NO\n";
            continue;
        }
        dfs(1, 0);
        if (cnt == n/k) cout << "YES\n";
        else cout << "NO";
    }
    return 0;
}