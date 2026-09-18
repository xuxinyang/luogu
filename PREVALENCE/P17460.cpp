#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N = 2e3+5;
constexpr ll mod = 1e9;
int n;
string s;
ll dp[N][N];    // 考虑原字符串的前 i 个字符，选出的子序列没有出现非法前缀，并且还有 j 个左括号未匹配的方案数
int main()
{
    cin >> n >> s;
    s = " " + s;
    dp[0][0] = 1;   // 空字符串
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i-1; j++)
        {
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            if (s[i] == '(')
                dp[i][j+1] = (dp[i][j+1] + dp[i-1][j]) % mod;
            else if (j > 0)
                dp[i][j-1] = (dp[i][j-1] + dp[i-1][j]) % mod;
        }
    }
    cout << dp[n][0] << "\n";
    return 0;
}