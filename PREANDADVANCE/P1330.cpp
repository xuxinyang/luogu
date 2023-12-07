#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
const int maxm = 1e5+5;
struct Edge
{
    int to, next;
} edges[maxm<<1];
int head[maxn], cnt, n, m, col[maxn], sum[2];
bool used[maxn];
void add(int u, int v)
{
    edges[++cnt] = Edge{v, head[u]};
    head[u] = cnt;
}
bool dfs(int node, int color)
{
    if (used[node])
    {
        if (col[node] == color) return true;
        return false;
    }
    used[node] = true;
    sum[col[node] = color]++;
    bool tf = true;
    for (int i = head[node]; i != 0 && tf; i = edges[i].next)
    {
        tf = tf && dfs(edges[i].to, 1 - color);
    }
    return tf;
}
int main()
{
    cin >> n >> m;
    int u, v;
    while (m--)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (used[i]) continue;
        sum[0] = sum[1] = 0;
        if (!dfs(i, 0))
        {
            printf("Impossible");
            return 0;
        }
        ans += min(sum[0], sum[1]);
    }
    cout << ans;
    return 0;
}