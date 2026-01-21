#include <bits/stdc++.h>
using namespace std;
#define ll long long
int prime[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
ll n, maxx, ans;
void dfs(int idx, ll cur, ll cnt, int last)
{
    if (cnt > maxx || cnt == maxx && cur < ans)
    {
        maxx = cnt;
        ans = cur;
    }
    if (idx == 10) return;
    ll p = prime[idx];
    for (int i = 1; i <= last; i++)
    {
        cur *= p;
        if (cur > n) break;
        dfs(idx+1, cur, cnt*(i+1), i);
    }
}
int main()
{
    cin >> n;
    dfs(0, 1, 1, 31);
    cout << ans;
    return 0;
}