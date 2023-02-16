#include <bits/stdc++.h>
using namespace std;
int n, m, x, f[1005][1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> x;
    int a, b, c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        for (int j = m; j >= b; j--)
        {
            for (int k = x; k >= c; k--)
                f[j][k] = max(f[j][k], f[j-b][k-c] + a);
        }
    }
    cout << f[m][x];
    return 0;
}