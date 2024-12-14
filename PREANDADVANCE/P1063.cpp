#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 105;
ll n, a[maxn<<1], f[maxn<<1][maxn<<1], ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)    // 将环拆分成链
    {
        cin >> a[i];
        a[i+n] = a[i];
    }
    for (int d = 2; d <= n+1; d++)   // 枚举区间长度
    {
        for (int i = 1; i+d-1<=2*n; i++)    // 枚举区间左端点
        {
            int j = d+i-1;  // 区间右端点
            for (int k = i+1; k <= i+d-2; k++)  // 求当前区间最值
                f[i][j] = max(f[i][j], f[i][k]+f[k][j] + a[i]*a[k]*a[j]);
        }
    }
    for (int i = 1; i <= n; i++) ans = max(ans, f[i][n+i]);
    cout << ans;
    return 0;
}