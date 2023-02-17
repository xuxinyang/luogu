#include <bits/stdc++.h>
using namespace std;
int a[2005], n, d, ans;
int main()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        if (a[i] <= a[i-1])
        {
            int f = (a[i-1]-a[i])/d + 1;
            a[i] += f * d;
            ans += f;
        }
    }
    cout << ans << endl;
    return 0;
}