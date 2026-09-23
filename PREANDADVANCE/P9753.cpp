#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 2e6+5;
constexpr int M = 5e6+3;
int n;
char s[N];
int fa[N], ch[N], tot;
ll cnt[N], key[N];
int head[M], nxt[N], to[N];
int get(int u, int c)
{
    ll k = 1LL * u * 26 + c;
    int h = k % M;
    for (int i = head[h]; i; i = nxt[i])
    {
        if (key[i] == k) return to[i];
    }
    ++ tot;
    fa[tot] = u; ch[tot] = c;
    key[tot] = k; to[tot] = tot;
    nxt[tot] = head[h], head[h] = tot;
    return tot;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> (s+1);
    int cur = 0;
    ll ans = 0;
    cnt[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int c = s[i] - 'a';
        if (cur && ch[cur] == c) cur = fa[cur];
        else cur = get(cur, c);
        ans += cnt[cur];
        cnt[cur]++;
    }
    cout << ans;
    return 0;
}