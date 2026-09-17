#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N = 2e3+5;
ll n, a[N], s[N], dp[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            ll t = s[i] - s[j];
            dp[i] = min(dp[i], dp[j] + t*t);
        }
    }    
    cout << dp[n];
    return 0;
}