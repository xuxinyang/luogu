#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4+5;
const int maxm = 1e5+5;
const int inf = 0x3f3f3f3f;
int n, m, head[maxn], tot, root;
int dp[maxn], tag[maxn], que[maxn], tail, ans;
struct Edge
{
    int to, next, w;
};
Edge edges[maxm];
void add(int u, int v, int w)
{
    edges[++tot] = {v, head[u], w};
    head[u] = tot;
}
void dfs(int x, int from, int lim)
{
    for (int i = head[x]; i; i = edges[i].next)
    {
        int y = edges[i].to;
        if (y == from) continue;
        dfs(y, x, lim);
    }
    tail = 0;
    for (int i = head[x]; i; i = edges[i].next)
    {
        int y = edges[i].to, w = edges[i].w;
        if (y == from) continue;
        que[++tail] = dp[y] + w;
    }
    sort(que+1, que+tail+1);
    for (int i = tail; i >= 1 && que[i] >= lim; i--)
        tail--, ans--;
    for (int i = 1; i <= tail; i++)
    {
        if (tag[i] != x)
        {
            int l = i+1, r = tail, pos = tail+1;
            while (l <= r)
            {
                int mid = (l+r)>>1;
                if (que[mid] + que[i] >= lim) pos = mid, r = mid-1;
                else l = mid+1;
            }
            while (pos <= tail && tag[pos] == x) pos++;
            if (pos <= tail) tag[i] = tag[pos] = x, ans--;
        }
    }
    dp[x] = 0;
    for (int i = tail; i >= 1; i--)
    {
        if (tag[i] != x) {dp[x] = que[i]; break;}
    }
    return;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n-1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    srand(time(0));
    root = rand()%n+1;
    int l = 0, r = inf, res = 0;
    while (l <= r)
    {
        int mid = (l+r)>>1;
        ans = m;
        memset(tag, 0, sizeof(tag));
        dfs(root, 0, mid);
        if (ans <= 0) res = mid, l = mid+1;
        else r = mid-1;
    }
    cout << res << endl;
    return 0;
}