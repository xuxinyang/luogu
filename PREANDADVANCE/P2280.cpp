#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+5;
const int inf = 5e3+1;
short ans, n, m, a[maxn][maxn], sum[maxn][maxn];
int main()
{
    cin >> n >> m;
    int x, y, z;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> z;
        a[x + 1][y + 1] = z;
    }
    for (int i = 1; i <= inf; i++)
    {
        for (int j = 1; j <= inf; j++)
        {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
    for (int i = m; i <= inf; i++)
    {
        for (int j = m; j <= inf; j++)
        {
            short k = sum[i][j]-sum[i-m][j]-sum[i][j-m]+sum[i-m][j-m];
            ans = ans > k ? ans : k;
        }
    }
    cout << ans << endl;
    return 0;
}