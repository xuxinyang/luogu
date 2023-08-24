#include <bits/stdc++.h>
using namespace std;
const int maxm = 12885;
const int maxn = 3405;
int n, m, w[maxn], d[maxn], f[maxm];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> d[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= w[i]; j--)
        {
            f[j] = max(f[j], f[j-w[i]]+d[i]);
        }
    }
    cout << f[m];
    return 0;
}