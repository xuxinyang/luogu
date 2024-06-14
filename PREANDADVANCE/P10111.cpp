#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
const int inf = 1e9;
int n, a[maxn], b[maxn], c[maxn];
int dp[maxn][maxn][3];  // dp[i][j][k]表示进行到第i轮，换了j次牌，当前出牌为k的最大得分
int ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 0; j < i; j++) // 第i轮换j次牌
        {
            for (int k = 0; k < 3; k++)
            {
                int s = 0, t = -inf;
                if ((c[i]+1)%3 == k) s = a[i]*2;
                if (c[i] == k) s = a[i];
                if (j < i-1 || i==1) t = max(t, dp[i-1][j][k]);
                if (j > 0)
                    t = max(t, max(dp[i-1][j-1][(k+1)%3], dp[i-1][j-1][(k+2)%3])-b[j]);
                dp[i][j][k] = t + s;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, max(dp[n][i][0], max(dp[n][i][1], dp[n][i][2])));
    }
    cout << ans;
    return 0;
}