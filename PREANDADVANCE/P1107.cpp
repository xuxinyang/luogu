#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+5;
const int maxh = 2e3+5;
int n, h, de;
int a[maxn][maxh], dp[maxn][maxh],  pre[maxn];
int main()
{
    cin >> n >> h >> de;
    for (int i = 1; i <= n; i++)
    {
        int t,x;
        scanf("%d", &t);
        while (t--)
        {
            scanf("%d", &x);
            a[i][x]++;
        }
    }
    int maxx = 0;
    for (int j = h; j >= 0; j--)
    {
        for (int i = 1; i <= n; i++)
        {
            dp[i][j] = a[i][j] + dp[i][j+1];
            dp[i][j] = max(dp[i][j], pre[j+de]+a[i][j]);
            pre[j] = max(pre[j], dp[i][j]);
            maxx = max(maxx, dp[i][j]);
        }
    }
    cout << maxx;
    return 0;
}