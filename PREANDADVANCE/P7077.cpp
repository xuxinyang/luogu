#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N = 1e5+5;
constexpr int E = 1e6+N;
constexpr ll MOD = 998244353;
int n, m, Q;
ll a[N], val[N], mul[N], cnt[N];
int type[N], pos[N];
int head[N], to[E], nxt[E], tot;
int in[N], que[N];
void add(int u, int v)
{
    ++tot;
    to[tot] = v; nxt[tot] = head[u];
    head[u] = tot;
    in[v]++;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++) 
    {
        cin >> type[i];
        mul[i] = 1;
        if (type[i] == 1) cin >> pos[i] >> val[i];
        else if (type[i] == 2) {cin >> val[i]; mul[i] = val[i];}
        else {
            int c;
            cin >> c;
            for (int j = 1; j <= c; j++)
            {
                int v;
                cin >> v;
                add(i, v);
            }
        }
    }
    type[0] = 3; mul[0] = 1;
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int v;
        cin >> v;
        add(0, v);
    }
    int l = 1, r = 0;
    for (int i = 0; i <= m; i++)
    {
        if (in[i] == 0) que[++r] = i;
    }
    while (l <= r)
    {
        int u = que[l++];
        for (int e = head[u]; e != 0; e = nxt[e])
        {
            int v = to[e];
            in[v]--;
            if (in[v] == 0) que[++r] = v;
        }
    }
    for (int i = r; i >= 1; i--)
    {
        int u = que[i];
        if (type[u] != 3) continue;
        for (int e = head[u]; e != 0; e = nxt[e])
        {
            int v = to[e];
            mul[u] = mul[u] * mul[v] % MOD;
        }
    }
    cnt[0] = 1;
    for (int i = 1; i <= r; i++)
    {
        int u = que[i];
        ll suf = 1;
        for (int e = head[u]; e != 0; e = nxt[e])
        {
            int v = to[e];
            cnt[v] = (cnt[v] + cnt[u] * suf) % MOD;
            suf = suf * mul[v] % MOD;
        }
    }
    for (int i = 1; i <= n; i++) a[i] = a[i] * mul[0] % MOD;
    for (int i = 1; i <= m; i++)
    {
        if (type[i] == 1) 
        {
            int p = pos[i];
            a[p] = (a[p] + val[i]*cnt[i]) % MOD;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}