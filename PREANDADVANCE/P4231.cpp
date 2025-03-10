#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e7+5;
ll n, m, f[maxn], ans1, ans2; 
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int l, r, s, e;
        cin >> l >> r >> s >> e;
        int d = (e-s)/(r-l);
        f[l] += s, f[l+1] += d-s;
        f[r+1] -= d+e, f[r+2] += e;
    }
    for (int i = 1; i <= n; i++) f[i] += f[i-1];
    for (int i = 1; i <= n; i++)
    {
        f[i] += f[i-1];
        ans1 ^= f[i], ans2 = max(ans2, f[i]);
    }
    cout << ans1 << " " << ans2;
    return 0;
}