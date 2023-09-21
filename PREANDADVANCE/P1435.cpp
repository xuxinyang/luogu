#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int dp[maxn][maxn];
string s1, s2;
int main()
{
    cin >> s1;
    s2 = s1;
    reverse(s1.begin(), s1.end());
    int k = s1.length();
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << k - dp[k][k];
    return 0;
}