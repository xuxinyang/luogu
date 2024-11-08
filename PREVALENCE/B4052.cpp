#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int inf = 1e9;
int n, m ,a[maxn], b[maxn];
long long ans;
int main()
{
    cin >> n >> m;
    ans = -inf;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans = max(a[i], (int)ans);
    }
    if (n == 1)
    {
        for (int i = 1; i <= m; i++)
        {
            int x;
            cin >> x;
            ans += x;
        }
        cout << ans;
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        if (ans+x > ans) ans += x;
    }
    cout << ans;
    return 0;
}