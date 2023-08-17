#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
const int maxm = maxn << 1;
const int mod = 1e4+7;
int n, u, v, w[maxn], head[maxn], tot, ans, maxx;
struct Edge
{
    int to, next;
};
Edge edges[maxm];
void add(int u, int v)
{
    edges[++tot] = Edge{v, head[u]};
    head[u] = tot;
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        int max1 = 0, max2 = 0;
        int s1 = 0, s2 = 0;
        for (int j = head[i]; j; j = edges[j].next)
        {
            int to = edges[j].to;
            if (w[to] > max1) max2 = max1, max1 = w[to];
            else if (w[to] > max2) max2 = w[to];
            s1 = (s1 + w[to]) % mod;
            s2 = (s2 + w[to] * w[to]) % mod;
        }
        s1 = s1 * s1 % mod;
        ans = (ans + s1 - s2 + mod) % mod;
        if (maxx < max1 * max2) maxx = max1 * max2;
    }
    cout << maxx << " " << ans;
    return 0;
}