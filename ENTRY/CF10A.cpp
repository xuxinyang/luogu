#include <bits/stdc++.h>
using namespace std;
struct Time
{
    int start;
    int end;
    int cost;
};
Time times[105];
int n, p1, p2, p3, t1, t2, ans;
int main()
{
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    for (int i = 1; i <= n; i++)
    {
        cin >> times[i].start >> times[i].end;
        times[i].cost = times[i].end - times[i].start;
        ans += times[i].cost * p1;
    }
    for (int i = 2; i <= n; i++)
    {
        int t = times[i].start - times[i-1].end;
        if (t <= t1) ans += p1 * t;
        else if (t > t1 && t <= t2 + t1)
            ans += p1 * t1 + p2 * (t - t1);
        else ans += p1 * t1 + p2 * t2 + p3 * (t-t1-t2);
    }
    cout << ans << endl;
    return 0;
}