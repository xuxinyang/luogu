#include <bits/stdc++.h>
using namespace std;
int n, k, c[405][405], sum[405][405], ans;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            sum[i][j] = sum[i][j-1] + c[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int res = 0;
            int rmin = max(1, i-k), rmax = min(n, i+k);
            for (int r = rmin; r <= rmax; r++)
            {
                int cmin = max(1, j - (k - abs(i - r))), cmax = min(n, j + (k - abs(i - r)));
                res += sum[r][cmax] - sum[r][cmin-1];
            }
            ans = max(res, ans);
        }
    }
    cout << ans;
    return 0;
}