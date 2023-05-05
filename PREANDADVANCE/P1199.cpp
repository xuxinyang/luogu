#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2+5;
int n, ans, a[maxn][maxn];
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sort(a[i] + 1, a[i] + n + 1);
        ans = max(ans, a[i][n-1]);
    }
    cout << 1 << "\n" << ans;
    return 0;
}