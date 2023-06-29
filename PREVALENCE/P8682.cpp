#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, a[maxn], diff = INT_MAX, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++)
    {
        diff = min(diff, a[i]-a[i-1]);
    }
    if (diff == 0)
    {
        cout << n;
        return 0;
    }
    ans = (a[n] - a[1]) / diff + 1;
    cout << ans;
    return 0;
}