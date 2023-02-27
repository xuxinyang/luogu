#include <bits/stdc++.h>
using namespace std;
int n, d, a[1005], ans;
int main()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j && abs(a[i]-a[j])<=d) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}