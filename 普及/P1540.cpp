#include <bits/stdc++.h>
using namespace std;
bool flag;
int m, n, x, ans, p = 1, q = 1;
int a[1005];
int main()
{
    cin >> m >> n;
    memset(a, -1, sizeof(a));
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        flag = 0;
        // 查找x是否在a[p]~a[q]范围内
        for (int i = p; i <= q; i++)
        {
            if (a[i] == x)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            ans++;
            if (q - p + 1 == m) p++;
            a[++q] = x;
        }
    }
    cout << ans << endl;
    return 0;
}