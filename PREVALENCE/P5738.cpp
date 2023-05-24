#include <bits/stdc++.h>
using namespace std;
int n, m, a[105][25], ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0, maxx = 0, minx = 10;
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            sum += a[i][j];
            maxx = max(maxx, a[i][j]);
            minx = min(minx, a[i][j]);
        }
        sum -= (maxx + minx);
        ans = max(sum, ans);
    }
    cout << fixed << setprecision(2) << 1.0*ans/(m-2);
    return 0;
}