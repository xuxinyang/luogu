#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4+5;
int x[505], y[505], n, m, k;
int flag[maxn], vis[maxn], sum, ans;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
        cin >> x[i] >> y[i], vis[x[i]] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;
        sum = m;
        // 判断每一行有多少格子被攻击了
        for (int j = 1; j <= k; j++)
        {
            if (flag[y[j]] != i)
                sum--;
            flag[y[j]] = i;
            if (x[j] < i)
            {
                if (y[j] + i - x[j] >= 1 && y[j] + i - x[j] <= m)
                {
                    if (flag[y[j] + i - x[j]] != i)
                        sum--;
                    flag[y[j] + i - x[j]] = i;
                }
                if (y[j] - i + x[j] >= 1 && y[j] - i + x[j] <= m)
                {
                    if (flag[y[j] - i + x[j]] != i)
                        sum--;
                    flag[y[j] - i + x[j]] = i;
                }
            }
            else
            {
                if (y[j] + (x[j] - i) >= 1 && y[j] + (x[j] - i) <= m)
                {
                    if (flag[y[j] + (x[j] - i)] != i)
                        sum--;
                    flag[y[j] + (x[j] - i)] = i;
                }
                if (y[j] - (x[j] - i) >= 1 && y[j] - (x[j] - i) <= m)
                {
                    if (flag[y[j] - (x[j] - i)] != i)
                        sum--;
                    flag[y[j] - (x[j] - i)] = i;
                }
            }
        }
        ans += sum;
    }
    cout << ans;
}