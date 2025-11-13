#include <bits/stdc++.h>
using namespace std;
int n, m, a[15][15], ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int l1 = 1; l1 <= n; l1++)
    {
        for (int r1 = 1; r1 <= m; r1++)
        {
            for (int l2 = l1; l2 <= n; l2++)
            {
                for (int r2 = r1; r2 <= m; r2++)
                {
                    int cnt = 0;
                    for (int i = l1; i <= l2; i++)
                    {
                        for (int j = r1; j <= r2; j++)
                        {
                            cnt += a[i][j];
                        }
                    }
                    if (cnt == (r2-r1+1)*(l2-l1+1))
                        ans = max(ans, cnt);
                }
            }
        }
    }
    cout << ans;
    return 0;
}