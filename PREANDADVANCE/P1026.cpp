#include <bits/stdc++.h>
using namespace std;
int p, n, m, k, dp[205][50], sum[205][205];
string s, a[10];
bool check(int l, int r)
{
    string x = s.substr(l, r - l + 1);
    for (int i = 1; i <= n; i++)
        if (x.find(a[i]) == 0)
            return true;
    return false;
}
int main()
{
    string ch;
    s += '0';
    cin >> p >> k;
    for (int i = 1; i <= p; i++)
    {
        cin >> ch;
        s += ch;
    }
    cin >> n;
    m = s.length() - 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = m; i >= 1; i--)
        for (int j = i; j >= 1; j--)
        {
            sum[j][i] = sum[j + 1][i];
            if (check(j, i))
                sum[j][i]++;
        }
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++)
        dp[i][i] = dp[i - 1][i - 1] + sum[i][i];
    for (int i = 1; i <= m; i++)
        dp[i][1] = sum[1][i];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= k && j < i; j++)
            for (int l = j; l < i; l++)
                dp[i][j] = max(dp[i][j], dp[l][j - 1] + sum[l + 1][i]);
    cout << dp[m][k];
    return 0;
}