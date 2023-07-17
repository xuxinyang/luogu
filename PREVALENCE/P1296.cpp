#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int n, d, a[maxn];
long long ans;
int main()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++)
    {
        int pos = upper_bound(a + i, a + n + 1, a[i] + d) - a - 1;
        ans += pos - i;
    }
    cout << ans;
    return 0;
}