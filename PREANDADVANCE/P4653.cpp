#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
double a[maxn], b[maxn], ans, s1, s2;
bool visa[maxn], visb[maxn];
int n, cnt;
bool cmp(double x, double y)
{
    return x > y;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1, cmp);
    int p = 1, q = 1;
    for (int i = 1, j = 1; i <= n && j <= n; )
    {
        p = i, q = j;
        s1 += a[p] * (!visa[p]);
        s2 += b[q] * (!visb[q]);
        visa[p] = visb[q] = 1;
        ans = max(ans, min(s1-i-j, s2-i-j));
        if (s1 >= s2) j++;
        if (s1 <= s2) i++;
    }
    cout << fixed << setprecision(4) << ans;
    return 0;
}