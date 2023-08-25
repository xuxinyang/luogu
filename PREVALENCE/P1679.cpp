#include <bits/stdc++.h>
using namespace std;
const int maxm = 1e5+5;
int m, v[20], f[maxm];  // f[j]表示不超过j的情况下最大能组成的数
int main()
{
    cin >> m;
    int n = sqrt(sqrt(m)) + 1;
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        v[i] = i * i * i * i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = v[i]; j <= m; j++)
        {
            f[j] = min(f[j], f[j-v[i]] + 1);
        }
    }
    cout << f[m];
    return 0;
}