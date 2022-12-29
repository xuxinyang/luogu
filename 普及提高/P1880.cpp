#include <bits/stdc++.h>
using namespace std;
int n, minx, maxx, f[205][205], g[205][205], a[205];
int s[205], sum[205][205];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)    // 成环
    {
        cin >> a[i];
        a[i+n] = a[i];
        s[i] = s[i-1] + a[i];
        sum[i][i] = i;
    }
    for (int i = 1 + n; i <= (n << 1); i++) 
    {
        s[i] = s[i-1] + a[i];
        sum[i][i] = i;
    }
    for (int i = (n<<1)-1; i; i--)
    {
        for (int j = i + 1; j <= (n << 1); j++)
        {
            int jc = 0, tmp = 0x3f3f3f3f;
            f[i][j] = max(f[i][j-1], f[i+1][j]) + s[j]-s[i-1];
            for (int k = sum[i][j-1]; k <= sum[i+1][j]; k++)
            {
                int tt = g[i][k] + g[k+1][j] + s[j] - s[i-1];
                if (tt < tmp) tmp = tt, jc = k;
            }
            sum[i][j] = jc, g[i][j] = tmp;
        }
    }
    minx = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        maxx = max(maxx, f[i][i+n-1]);
        minx = min(minx, g[i][i+n-1]);
    }
    cout << minx << "\n" << maxx << "\n";
    return 0;
}