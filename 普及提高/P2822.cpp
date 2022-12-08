#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000;
int t, k, n, m;
int c[2005][2005], f[2005][2005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t >> k;
    c[1][1] = 1;
    for (int i = 0; i <= 2000; i++)
        c[i][0] = 1;
    for (int i = 2; i <= 2000; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
        }
    }
    for (int i = 2; i <= 2000; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
            if (c[i][j] == 0)
                f[i][j] += 1;
        }
        f[i][i + 1] = f[i][i];
    }
    while (t--)
    {
        cin >> n >> m;
        if (m > n)
            m = n;
        cout << f[n][m] << "\n";
    }
    return 0;
}