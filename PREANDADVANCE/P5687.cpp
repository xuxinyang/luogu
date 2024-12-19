#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5 + 5;
int n, m;
ll a[maxn], b[maxn], s[maxn], ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 1; i <= m; i++) s[i] = s[i - 1] + b[i];
    ans = a[1] * (m - 1) + b[1] * (n - 1);
    for (int i = 2; i <= n; i++)
    {
        int pos = lower_bound(b + 2, b + m + 1, a[i]) - b;
        ans += s[pos - 1] - b[1] + a[i] * (m - pos + 1);
    }
    cout << ans << endl;
    return 0;
}