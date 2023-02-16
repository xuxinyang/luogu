#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e4+5;
ll n, a[maxn], b[maxn], ans;
//  -1 1
//   2 9
//   5 11
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
    {
        ans += (b[i] - a[i]);
        if (a[i] < b[i-1] && i >= 2) ans -= (b[i-1]-a[i]);
    }
    cout << ans << endl;
    return 0;
}