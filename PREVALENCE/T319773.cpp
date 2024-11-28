#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int inf = INT_MAX;
int t, n, a[maxn], b[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        int minx = inf, maxx = -inf;
        for (int i = 1; i <= n; i++)
        {
            minx = min(minx, a[i]-b[i]);
            maxx = max(maxx, a[i]+b[i]);
        }
        cout << (minx+maxx)/2.0 << "\n";
    }
    return 0;
}