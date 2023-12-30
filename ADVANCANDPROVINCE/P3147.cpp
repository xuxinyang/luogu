#include <bits/stdc++.h>
using namespace std;
const int maxn = 60;
const int maxm = 262144 + 5;
int n, ans, x, f[maxn][maxm];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        f[x][i] = i + 1;
    }
    for (int i = 2; i <= 58; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!f[i][j])
                f[i][j] = f[i-1][f[i-1][j]];
            if (f[i][j])
                ans = i;
        }
    }
    cout << ans;
    return 0;
}