#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5+5;
ll n, a[maxn], cnt[maxn], s[maxn];
ll ans, t;
bool vis[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
    for (int i = 1; i < maxn; i++) s[i] = s[i-1]+cnt[i];
    for (int i = 1; i < maxn; i++)
    {
        ans += (s[maxn-1]-s[i])*cnt[i]*s[i-1];
    }
    cout << ans;
    return 0;
}