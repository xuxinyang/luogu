#include <bits/stdc++.h>
using namespace std;
int n, m, f[20], w[20][20], ans[20][20];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> w[i][j];
        }
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 1; k <= j; k++)
            {
                if (f[j-k] + w[i][k] > f[j])
                {
                    f[j] = f[j-k] + w[i][k];
                    ans[i][j] = k;
                }
            }
        }
    }
    cout << f[m] << endl;
    for (int i = 1, j = m; i <= n; i++)
    {
        cout << i << " " << ans[i][j] << endl;
        j -= ans[i][j];
    }
    return 0;
}