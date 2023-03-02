#include <bits/stdc++.h>
using namespace std;
int n, x, a[1005], ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        ans = max(++a[x], ans);
    }
    cout << ans << " ";
    ans = 0;
    for (int i = 1; i <= 1000; i++)
    {
        if (a[i] != 0) ans++;
    }
    cout << ans << endl;
    return 0;
}