#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
const int maxm = 1e4+5;
int n, m, p[maxn], t[maxn], f[maxm];
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++) cin >> p[i] >> t[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = t[i]; j <= m; j++)
        {
            f[j] = max(f[j], f[j-t[i]]+p[i]);
        }
    }
    cout << f[m];
    return 0;
}