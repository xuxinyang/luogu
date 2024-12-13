#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int mod = 1e9+7;
inline ll qpow(ll x, int y = mod-2)
{
    ll res = 1;
    while (y)
    {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
int n, m, t;
ll v, ans;
map<int, int> mp;
map<int, int>::iterator it1, it2;
inline void solve()
{
    cin >> n >> m >> v;
    mp.clear(); ans = 1;
    for (int i = 0, c, d; i < m; i++)
    {
        cin >> c >> d;
        if (mp.count(c) && mp[c] != d) ans = 0;   // 不存在
        else mp[c] = d;
    }
    if (!ans)
    {
        cout << "0\n";
        return;
    }
    it1 = it2 = mp.begin();
    ans = qpow(v, ((*it1).first-1)*2);
    it1++;
    for (; it1 != mp.end(); it1++, it2++)
    {
        int x = (*it2).first, y = (*it1).first;
        ans = ans * (qpow(v, (y-x)*2)-qpow(v, y-x-1)*(v-1)%mod+mod)%mod;
    }
    ans = ans * qpow(v, (n-(*it2).first)*2)%mod;
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}