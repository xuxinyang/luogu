#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 105;
const int maxq = 5e4+5;
int t, n;
ll p, q, v[maxn], w[maxn], dp[maxq]; 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> p >> q;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
        for (int i = 1; i <= n; i++)
        {
            for (int j = q; j >= w[i]; j--)
            {
                dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
            }
        }
        bool flag = false;
        for (int i = 1; i <= q; i++)
        {
            if (dp[i] >= p)
            {
                cout << i << "\n";
                flag = true;
                break;
            }
        }
        if (!flag) cout << "-1\n";
    }
    return 0;
}