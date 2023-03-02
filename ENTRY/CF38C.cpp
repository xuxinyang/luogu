#include <bits/stdc++.h>
using namespace std;
int n, l, ans = 0, mx = -1, a[105];
int main()
{
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = l; i <= 100; i++)
    {
        ans = 0;
        for (int j = 1; j <= n; j++)
            ans = ans + a[j] / i;
        mx = max(mx, ans * i);
    }
    cout << mx;
    return 0;
}