#include <bits/stdc++.h>
using namespace std;
int n, a[100005], b[1000005], ans[1000005], maxx;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]]++;
        maxx = max(maxx, a[i]);
    }
    for (int i = 1; i <= maxx; i++)
    {
        if (b[i] != 0)
            for (int j = 1; j * i <= maxx; j++) ans[j*i] += b[i];
    }
    for (int i = 1; i <= n; i++) cout << ans[a[i]] - 1 << "\n";
    return 0;
}