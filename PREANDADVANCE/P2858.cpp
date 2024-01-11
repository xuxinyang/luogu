#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+5;
int n, f[maxn][maxn], v[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) f[i][i] = v[i]*n;
    for (int i = 2; i <= n; i++)
    {
        for (int l = 1; l <= n; l++)
        {
            int r = l + i - 1;
            if (r > n) break;
            f[l][r] = max(f[l][r-1] + v[r]*(n-i+1), f[l+1][r] + v[l]*(n-i+1));
        }
    }
    cout << f[1][n];
    return 0;
}