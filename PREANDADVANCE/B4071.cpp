#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e3+5;
ll n, m, p, c, cnt[maxn];
ll ans;
vector<ll> ve[maxn];
ll calc(int x)
{
    ll res = 0, cur = cnt[1];
    vector<ll> tmp;
    for (int i = 2; i <= n; i++)
    {
        ll ned = max((int)ve[i].size()-x+1, 0);
        for (int j = 0; j < ned; j++)
        {
            res += ve[i][j];
        }
        cur += ned;
        for (int j = ned; j < ve[i].size(); j++)
        {
            tmp.push_back(ve[i][j]);
        }
    }
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < x-cur; i++)
    {
        res += tmp[i];
    }
    return res;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> p >> c;
        ve[p].push_back(c);
        cnt[p]++;
    }
    for (int i = 1; i <= n; i++)
    {
        sort(ve[i].begin(), ve[i].end());
    }
    ans = 1e18;
    for (int i = max(1ll, cnt[1]); i <= m; i++)
    {
        ans = min(ans, calc(i));
    }
    cout << ans;
    return 0;
}