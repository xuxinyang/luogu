#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e3+5;
const int mod = 1e9+7;
int c[30], n, sum, ans;
string s; 
int fac(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = (res * i) % mod;
    return res;
}
int cal(int x)
{
    int  res = 1;
    for (int i = 1;  x > i; i += 2)
        res = res * i % mod * 2 % mod;
    if (x & 1) res = res * x % mod;
    return res;
}
signed main()
{
    cin >> n;
    sum = fac(n);
    cin >> s;
    for (int i = 0; i < s.length(); i++) c[s[i]-'a']++;
    // 统计奇数字母个数有多少个
    int cnt = 0;
    for (int i = 0; i < 26; i++)
        if (c[i]&1) cnt++;
    // 如果字母是奇数个的个数超过1种，则不可能够成回文
    if (cnt > 1)
    {
        cout << sum << endl;
        return 0;
    }
    ans = 1, cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        ans = ans * cal(c[i]) % mod;
        cnt += c[i] / 2;
    }
    cnt = fac(cnt);
    ans = ans * cnt % mod;
    ans = (sum + mod - ans) % mod;
    cout << ans;
    return 0;
}