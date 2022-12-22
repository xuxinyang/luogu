#include <bits/stdc++.h>
using namespace std;
double maxn = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    double n, a, x;
    cin >> n >> a >> x;
    while (n--)
    {
        double t, v;
        cin >> t >> v;
        double ans = t;
        if (x <= v * v / (2 * a)) ans += sqrt(2 * x / a);
        else ans += x/v, ans += v/(2*a);
        if (maxn > ans) ans = maxn;
        else maxn = ans;
        ans *= 10000;
        ans = floor(ans);
        ans /= 10000;
        cout << fixed << setprecision(4) << ans << "\n";
    }
    return 0;
}