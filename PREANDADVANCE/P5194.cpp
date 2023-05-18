#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e3+5;
ll n, c, ans, a[maxn], s[maxn];
void dfs(int start, ll sum)
{
    if (sum > c) return;
    if (s[start-1] + sum <= c)
    {
        ans = max(ans, s[start-1] + sum);
        return;
    }
    ans = max(sum, ans);
    for (int i = 1; i < start; i++)
    {
        dfs(i, sum + a[i]);
    }
}
int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    dfs(n+1, 0);
    cout << ans;
    return 0;
}