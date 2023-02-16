#include <bits/stdc++.h>
using namespace std;
const int mod = 1e5+3;
const int mfxn = 1e6+5;
int n, k, f[mfxn];
int main()
{
    cin >> n >> k;
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i <= k) f[i] = f[i-1] * 2 % mod;
        else f[i] = f[i-1]*2 - f[i-k-1], f[i] %= mod;
    }
    cout << (f[n] + mod) % mod << endl;
    return 0;
}