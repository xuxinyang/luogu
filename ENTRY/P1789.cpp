#include <bits/stdc++.h>
using namespace std;
int n, m, p, ans, a[105][105];
int main()
{
    cin >> n >> m >> p;
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        for (int j = x-2; j <= x+2; j++)
        {
            if (j < 1 || j > n) continue;
            for (int k = y-2; k <= y+2; k++)
            {
                if (k < 1 || k > n) continue;
                if (abs(x-j)+abs(y-k) <= 2)
                {
                    a[j][k] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= p; i++)
    {
        cin >> x >> y;
        for (int j = x-2; j <= x+2; j++)
        {
            if (j < 1 || j > n) continue;
            for (int k = y-2; k <= y+2; k++)
            {
                if (k < 1 || k > n) continue;
                a[j][k] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}