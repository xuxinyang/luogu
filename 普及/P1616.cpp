#include <bits/stdc++.h>
using namespace std;
long long f[10000005], t, m, v[10005], w[10005];
int main()
{
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> v[i] >> w[i];
    }
    // 完全背包模板
    for (int i = 1; i <= m; i++)
    {
        for (int j = v[i]; j <= t; j++)
        {
            f[j] = max(f[j], f[j-v[i]] + w[i]);
        }
    }
    cout << f[t] << endl;
    return 0;
}