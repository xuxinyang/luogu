#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+5;
string s1, s2;
int k, dp[maxn][maxn], len1, len2;
int main()
{
    cin >> s1 >> s2;
    cin >> k;
    len1 = s1.length(), len2 = s2.length();
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= len1; i++) dp[i][0] = i*k;
    for (int i = 1; i <= len2; i++) dp[0][i] = i*k;
    dp[0][0] = 0;
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            dp[i][j] = min(
                min(dp[i][j], dp[i-1][j-1]+abs(s1[i-1]-s2[j-1])), 
                min(dp[i-1][j]+k, dp[i][j-1]+k)
                );
        }
    }
    cout << dp[len1][len2];
    return 0;
}