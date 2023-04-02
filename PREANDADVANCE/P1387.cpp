#include <bits/stdc++.h>
using namespace std;
int a[105][105], f[105][105], n, m, ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
                f[i][j] = min(f[i-1][j-1], min(f[i-1][j], f[i][j-1])) + 1;
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}