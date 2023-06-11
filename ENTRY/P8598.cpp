#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int minx = INT_MAX, maxx = 0, n, a[maxn], x;
int ans1, ans2;
int main()
{
    cin >> n;
    while (cin >> x)
    {
        a[x] += 1;
        maxx = max(maxx, x);
        minx = min(minx, x);
    }
    for (int i = minx; i <= maxx; i++)
    {
        if (a[i] == 0) ans1 = i;
        if (a[i] == 2) ans2 = i;
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}