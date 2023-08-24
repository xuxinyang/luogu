#include <bits/stdc++.h>
using namespace std;
const int maxh = 45005;
const int maxn = 505;
int h, n, a[maxn], f[maxh];
int main()
{
    cin >> h >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = h; j >= a[i]; j--)
        {
            f[j] = max(f[j], f[j-a[i]] + a[i]);
        }
    }
    cout << f[h];
    return 0;
}