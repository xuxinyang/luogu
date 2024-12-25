#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+5;
const int maxm = 1e5+5;
int n, m, x;
ll ans = 0;
struct Point
{
    ll idx, cap;
};
Point points[maxn];
struct Carry
{
    ll a, b;
}lf[maxm], ri[maxm];
Carry carries[maxm];
int main()
{
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) cin >> points[i].idx >> points[i].cap;
    sort(points+1, points+n+1, [](Point a, Point b){return a.idx < b.idx;});
    int p = 0, q = 0, u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        if (u > v) lf[++p] = {u, v};
        else ri[++q] = {u, v};
    }
    sort(lf+1, lf+p+1, [](Carry A, Carry B){return A.a-A.b > B.a-B.b;});
    sort(ri+1, ri+q+1, [](Carry A, Carry B){return A.b-A.a > B.b-B.a;});
    // 处理左侧
    int pos = 1;
    for (int i = 1; i <= p; i++)
    {
        if (points[pos].cap == 0) pos++;
        ans += 2ll*lf[i].a*points[pos].idx + 2ll*lf[i].b*(x-points[pos].idx);
        points[pos].cap--;
    }
    // 处理右侧
    pos = n;
    // cout << ans << "\n";
    for (int i = 1; i <= q; i++)
    {
        if (points[pos].cap == 0) pos--;
        ans += 2ll*ri[i].a*points[pos].idx + 2ll*ri[i].b*(x-points[pos].idx);
        points[pos].cap--;
    }
    cout << ans;
    return 0;
}