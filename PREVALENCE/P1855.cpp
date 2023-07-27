#include <bits/stdc++.h>
using namespace std;
const int maxm = 205;
const int maxt = 205;
int n, m, t, f[maxm][maxt], money[maxm], cost[maxt];
int main()
{
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> money[i] >> cost[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= money[i]; j--)
        {
            for (int k = t; k >= cost[i]; k--)
            {
                f[j][k] = max(f[j][k], f[j-money[i]][k-cost[i]] + 1);
            }
        }
    }
    cout << f[m][t];
    return 0;
}