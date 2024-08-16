#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5+5;
int n, f[maxn], g[maxn], a[maxn], sum, tot;
int query()
{
    int res = -inf;
    for (int i = 1; i <= n; i++) f[i] = max(f[i-1], 0) + a[i];
    for (int i = n; i > 0; i--) g[i] = max(g[i+1], 0) + a[i];
    for (int i = 1; i <= n; i++) f[i] = max(f[i-1], f[i]);
    for (int i = n; i > 0; i--) g[i] = max(g[i+1], g[i]);
    for (int i = 1; i < n; i++) res = max(res, f[i] + g[i+1]);
    return res;
}
int main()
{
    cin >> n;
    memset(f, ~0x3f, sizeof(f));
    memset(g, ~0x3f, sizeof(g));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        tot += a[i] > 0;
    }
    int t1 = query();
    if (tot == 1) cout << t1;
    else
    {
        for (int i = 1; i <= n; i++) a[i] = -a[i];
        int t2 = sum + query();
        if (!t2) t2 = -inf;
        cout << max(t1, t2);
    }
    return 0;
}