#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, k, a[505][505], sum[505][505], l, r, s[505];
ll ans, cur;
int main()
{
    cin >> n >> m >> k;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            sum[i][j] = sum[i-1][j] + a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            for (int k = 1; k <= m; k++)
                s[k] = sum[j][k] - sum[i-1][k]; // i-j行的单列数据和
            l = 1, r = 1, cur = 0;
            for (r = 1; r <= m; r++)
            {
                cur += s[r];
                if (cur <= k) ans += r - l + 1;
                else
                { 
                    while (cur > k) cur -= s[l++];
                    ans += r - l + 1;
                }
                
            }
        }
    }
    cout << ans;
    return 0;
}