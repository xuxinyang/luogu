#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,no-stack-protector")
#define re register
#define ll long long
const int maxn = 5e5+5;
int n, q, a[maxn], dep[maxn], stk[maxn], top, first[maxn], cnt, f[maxn][20];
ll lastans, s[maxn][20];
struct Edge
{
    int v, nxt;
}edges[maxn];
inline int read()
{
    int data = 0;
    char ch;
    ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) data = (data << 1) + (data << 3) + (ch ^ 48), ch = getchar();
    return data;
}
inline void add(int u, int v)
{
    edges[++cnt] = (Edge) {v, first[u]}, first[u] = cnt;
}
void dfs(int u)
{
    for (int re i = 1; (1 << i) < dep[u]; ++i)
        f[u][i] = f[f[u][i-1]][i-1], s[u][i] = s[u][i-1] + s[f[u][i-1]][i-1];
    for (int re v, i = first[u]; i; i = edges[i].nxt)
    {
        v = edges[i].v;
        if (!dep[v]) s[v][0] = (ll)(u-v) * a[v], f[v][0] = u, dep[v] = dep[u] + 1, dfs(v);
    }
}
ll ask(int x, int l, ll re ret = 0)
{
    for (int re i = 19; ~i; --i)
    {
        if (f[x][i] && f[x][i] - x <= l)
            ret += s[x][i], l -= (f[x][i] - x), x = f[x][i];
    }
    ret += (ll)l * a[x];
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    n = read(), q = read();
    for (int re i = 1; i <= n; ++i) a[i] = read();
    a[n+1] = INT_MAX;
    for (int re i = 1; i <= n + 1; ++i)
    {
        while (top && a[stk[top]] < a[i]) add(i, stk[top--]);
        stk[++top] = i;
    }
    dfs(n + 1);
    while (q--)
    {
        ll re u = read(), v = read();
        int re l = 1 + (u ^ lastans) % n, len = 1 + (v ^ (lastans + 1)) % (n - l + 1);
        printf("%lld\n", lastans = ask(l, len));
    }
    return 0;
}