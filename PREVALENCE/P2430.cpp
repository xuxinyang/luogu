#include <bits/stdc++.h>
using namespace std;
const int maxm = 5e3+5;
const int maxt = 5e3+5;
int l1, l2, m, n, t[maxm], w[maxm], v[maxm];
int dp[maxt], T;
int main()
{
    cin >> l1 >> l2 >> m >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= m; i++) cin >> w[i] >> v[i];
    cin >> T;
    T = T * l1 / l2;
    for (int i = 1; i <= m; i++)
    {
        for (int j = T; j >= t[w[i]]; j--)
        {
            dp[j] = max(dp[j], dp[j-t[w[i]]] + v[i]);
        }
    }
    cout << dp[T];
    return 0;
}