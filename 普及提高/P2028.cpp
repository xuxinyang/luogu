#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll n, k, p, f[10005][1005];
int main()
{
    cin >> n >> k >> p;
    f[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        f[i][1] = 1;
        for (int j = 2; j <= k; j++)
            f[i][j] = ((j % p) * (f[i-1][j] % p) % p + (f[i-1][j-1] % p)) % p;
    }
    cout << f[n][k] << endl;
    return 0;
}