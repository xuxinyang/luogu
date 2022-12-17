#include <bits/stdc++.h>
using namespace std;
int k, d, m, f, o;
priority_queue<int, vector<int>, less<int> > kp, dp, mp, fp;
int q, x, y, z;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k >> d >> m >> f;
    for (int i = 1; i <= k; i++) cin >> o, kp.push(o);
    for (int i = 1; i <= d; i++) cin >> o, dp.push(o);
    for (int i = 1; i <= m; i++) cin >> o, mp.push(o);
    for (int i = 1; i <= f; i++) cin >> o, fp.push(o);
    cin >> q;
    while (q--)
    {
        cin >> x >> y >> z;
        int ans = 0;
        ans += kp.top(), kp.pop();
        while (x--) ans += dp.top(), dp.pop();
        while (y--) ans += mp.top(), mp.pop();
        while (z--) ans += fp.top(), fp.pop();
        cout << fixed << setprecision(2) << ans/11.0 << "\n";
    }
    return 0;
}