#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
double d, x[maxn], y[maxn], last;
struct Radar
{
    double l, r;
} radars[maxn];
bool cmp(Radar A, Radar B)
{
    return A.r < B.r;
}
int n, ans;
int main()
{
    cin >> n >> d;
    for (int i = 1; i <= n; i++) 
    {
        cin >> x[i] >> y[i];
        if (y[i] > d)
        {
            puts("-1");
            return 0;
        }
        radars[i].l = x[i]-sqrt(d*d-y[i]*y[i]);
        radars[i].r = x[i]+sqrt(d*d-y[i]*y[i]);
    }
    sort(radars+1, radars+n+1, cmp);
    last = radars[1].r; ans = 1;
    for (int i = 2; i <= n; i++)
    {
        if (last < radars[i].l) ans++, last = radars[i].r; 
    }
    cout << ans;
    return 0;
}