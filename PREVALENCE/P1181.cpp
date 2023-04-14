#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn], n, m, ans, sum;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (sum + a[i] > m)
        {
            ans++;
            sum = a[i];
        }
        else sum += a[i];
    }
    cout << ans << endl;
    return 0;
}