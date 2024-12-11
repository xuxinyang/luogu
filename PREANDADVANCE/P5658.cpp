#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e5+5;
int n, head[maxn], fa[maxn], tot, s[maxn], top;
ll sum[maxn], lst[maxn], ans;
char c[maxn];
struct Edge
{
    int to, next;
};
Edge edges[maxn];
void add(int u, int v)
{
    edges[++tot] = {v, head[u]};
    head[u] = tot;
}
void dfs(int u)
{
    int res = 0;
    if (c[u] == ')')
    {
        if (top) res = s[top], lst[u] = lst[fa[res]]+1, --top;
    }
    else if (c[u] == '(') s[++top] = u;
    sum[u] = sum[fa[u]] + lst[u];
    for (int i = head[u]; i; i = edges[i].next) dfs(edges[i].to);
    if (res != 0) s[++top] = res;
    else if (top) --top;
}
int main()
{
    cin >> n;
    cin >> (c+1);
    for (int i = 2; i <= n; i++)
    {
        int f;
        cin >> f;
        add(f, i);
        fa[i] = f;
    }
    dfs(1);
    for (int i = 1; i <= n; i++) ans ^= sum[i]*i;
    cout << ans;
    return 0;
}