#include <bits/stdc++.h>
using namespace std;
char c1[2005], c2[2005];
int dp[2005][2005];
int main()
{
    cin >> c1 >> c2;
    int len1 = strlen(c1), len2 = strlen(c2);
    for (int i = 1; i <= len1; i++) dp[i][0] = i;
    for (int j = 1; j <= len2; j++) dp[0][j] = j;
    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
        {
            if (c1[i-1] == c2[j-1]) dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
        }
        cout << dp[len1][len2] << endl;
    return 0;
}