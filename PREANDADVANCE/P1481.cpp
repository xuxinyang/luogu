#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+5;
const int maxz = 105;
int n, dp[maxn], ans;
string s[maxn];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        dp[i] = 1;
        for (int j = i - 1; j >= 1; j--)
        {
            if (s[i].length() >= s[j].length() && s[i].substr(0, s[j].length()) == s[j])
            {
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
        ans = max(ans, dp[i]);
    }   
    cout << ans;
    return 0;
}