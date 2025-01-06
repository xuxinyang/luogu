#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 20;
const int maxm = 200;
const int mod = 1e9+7;
ll t, l, r, a[20], num, f[maxn][200];
ll dfs(int pos, int sum, bool limit)
{
    if (!pos) return sum;
    if (!limit && f[pos][sum] > 0) return f[pos][sum];
    int bound = limit ? a[pos] : 9;
    ll res = 0;
    for (int i = 0; i <= bound; i++)
        res = (res + dfs(pos-1, sum + i, limit && i == bound)) % mod;
    if (!limit) f[pos][sum] = res;
    return res;
}
ll solve(ll x)
{
    int pos = 0;
    while (x)
    {
        a[++pos] = x % 10;
        x /= 10; 
    }
    return dfs(pos, 0, 1) % mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    memset(f, -1, sizeof(f));
    while (t--)
    {
        cin >> l >> r;
        cout << (solve(r) - solve(l-1) + mod) % mod << "\n";
    }
    return 0;
}