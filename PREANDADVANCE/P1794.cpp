#include <bits/stdc++.h>
using namespace std;
const int maxv = 505;
const int maxg = 505;
const int maxn = 505;
int V, G, n, t[maxn], v[maxv], g[maxg], dp[maxv][maxg]; 
int main()
{
    cin >> V >> G;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> v[i] >> g[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = V; j >= v[i]; j--)
        {
            for (int k = G; k >= g[i]; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j-v[i]][k-g[i]] + t[i]);
            }
        }
    }
    cout << dp[V][G];
    return 0;
}