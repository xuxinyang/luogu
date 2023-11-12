#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
int n, m;
int a[105], x, f[105][105];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> x;
        a[i] <<= 18;
        a[i] += x;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
        a[i] = a[i]&0x0000FFFF;
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i <= n; i++)
        f[i][1] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            for (int k = j - 1; k <= i - 1; k++)
                f[i][j] = min(f[i][j], f[k][j - 1] + abs(a[i] - a[k]));
    int ans = inf;
    for (int i = n - m; i <= n; i++)
        ans = min(ans, f[i][n - m]);
    printf("%d\n", ans);
    return 0l;
}