#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int l[maxn], r[maxn], a[maxn];
int n, m, ans;
char c[3];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            l[j] = r[j] = j;
        }
        for (int j = 1; j <= m; j++)
        {
            cin >> c;
            if (c[0] == 'R') a[j] = 0;
            else a[j]++;
        }
        // 找最大能到达右边界F的个数
        for (int j = 1; j <= m; j++)
        {
            while (l[j] != 1 && a[l[j]-1] >= a[j]) l[j] = l[l[j]-1];
        }
        // 找最大能到达左边界F的个数
        for (int j = m; j >= 1; j--)
        {
            while (r[j] != m && a[r[j]+1] >= a[j]) r[j] = r[r[j]+1];
        }
        for (int j = 1; j <= m; j++)
            ans = max(ans,(r[j]-l[j]+1) * a[j]);
    } 
    cout << ans * 3;
    return 0;
}