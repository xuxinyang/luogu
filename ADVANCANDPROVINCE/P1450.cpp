#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxs = 1e5;
ll n, d[5], c[5], s, f[maxs+5];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= 4; i++) cin >> c[i];
    f[0] = 1;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = c[i]; j <= maxs; j++)
            f[j] += f[j-c[i]];
    }
    cin >> n;
    while (n--)
    {
        cin >> d[1] >> d[2] >> d[3] >> d[4] >> s;
        ll ans = f[s];
        for (int k = 1; k < (1<<4)-1; k++)
        {
            ll cur = s;
            bool flag = 0;
            for (int i = k, j = 1; i; i>>=1, j++)
            {
                if (i & 1) flag ^= 1, cur -= (d[j]+1) * c[j];
            }
            if (cur >= 0) flag ? ans -= f[cur]: ans += f[cur];
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
in:
1 2 5 10 2
3 2 3 1 10
1000 2 2 2 900
out:
4
27
*/