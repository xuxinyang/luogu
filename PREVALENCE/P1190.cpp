#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
int a[maxn], ans, n, m, t;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    t = m + 1;
    while (t <= m + n)
    {
        for (int i = 1; i <= m; i++)
        {
            if (--a[i] == 0) a[i] = a[t++]; 
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}