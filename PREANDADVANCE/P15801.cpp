#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n, ans, l[N], r[N], dep[N], f[N], c[N];
void dfs(int u)
{
    int lt = l[u], rt = r[u];
    if (lt) dfs(lt);
    if (rt) dfs(rt);
    dep[u] = max(dep[lt], dep[rt])+1;
    if (f[lt] && f[rt] && dep[lt] == dep[rt]) f[u] = 1;
    if (f[lt] && c[rt] && dep[lt] == dep[rt]) c[u] = 1;
    if (c[lt] && f[rt] && dep[lt]-1 == dep[rt]) c[u] = 1;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
    dep[0] = 0;
    c[0] = f[0] = 1;
    dfs(1);
    for (int i = 1; i<= n; i++) ans += c[i];
    cout << ans;
    return 0;
}