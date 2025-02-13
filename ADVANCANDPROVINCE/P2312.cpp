#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e4 + 7;
const int Mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int n, m, cnt, ans[maxn];
ll a[105], b[105];
bool vis[mod];
bool calc(int x, int p, ll *t)
{
    ll res = t[n];
    for (int i = n-1; i >= 0; i--) res = (res*x+t[i])%p;
    return res == 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
    {
        ll x = 0, X = 0, f = 0;
        char c = getchar();
        while (c < '0' || c > '9')
        {
            if (c == '-') f = 1;
            c = getchar();
        }
        while (c >= '0' && c <= '9')
        {
            x = (x<<1)+(x<<3) + c - '0';
            X = (X<<1)+(X<<3) + c - '0';
            x %= mod, X %= Mod;
            c = getchar();
        }
        a[i] = f ? mod-x:x;
        b[i] = f ? Mod-X:X;
    }
    for (int i = 0; i < mod; i++)
        if (calc(i, mod, a)) vis[i] = 1;
    for (int i = 1; i <= m; i++)
        if (vis[i%mod]&&calc(i, Mod, b)) ans[++cnt] = i;
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++) printf("%d\n", ans[i]);
    return 0;
}