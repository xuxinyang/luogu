#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
ll n, a[N], dp[N];  // dp[i]表示前i个字符划分后获取的最大价值
string s;
int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1]+a[1];
        set<char> st;
        st.insert(s[i-1]);
        for (int j = i-2; j >= 0; j--)
        {
            if (st.count(s[j])) break;
            st.insert(s[j]);
            dp[i] = max(dp[i], dp[j]+a[i-j]);
        }
        // cout << dp[i] << " ";
    }
    cout << dp[n];
    return 0;
}