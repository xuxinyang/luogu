#include <bits/stdc++.h>
using namespace std;
int n, m, a[1005][1005], ans[1005], pre[1005], res;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++) cin >> ans[i];
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= m; j++)
        {
            sum += a[j][i];
        }
        pre[i] = sum > m/2 ? 1 : 0;
    }
    for (int i = 1; i <= n; i++)
        if (pre[i] == ans[i]) res++;
    cout << res;
    return 0;
}