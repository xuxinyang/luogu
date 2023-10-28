#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+5;
struct P
{
    int x, y;
};
P points[maxn];
int L, W, n, ans;
int main()
{
    cin >> L >> W >> n;
    for (int i = 1; i <= n; i++) cin >> points[i].x >> points[i].y;
    points[++n] = P{0, 0};
    points[++n] = P{0, W};
    points[++n] = P{L, 0};
    points[++n] = P{L, W};
    int xl, xr, yd, yu;
    sort(points + 1, points + n + 1, [](P a, P b){
        return a.x == b.x ? a.y < b.y : a.x < b.x;
    });
    for (int i = 1; i <= n; i++)
    {
        xl = points[i].x, yd = 0, yu = W;
        for (int j = i + 1; j <= n; j++)
        {
            xr = points[j].x;
            ans = max(ans, (xr-xl) * (yu-yd));
            if (points[j].y < points[i].y) yd = max(yd, points[j].y);
            else yu = min(yu, points[j].y);
        }
    }
    for (int i = n; i >= 1; i--)
    {
        xl = points[i].x, yd = 0, yu = W;
        for (int j = i - 1; j >= 1; j--)
        {
            xr = points[j].x;
            ans = max(ans, (xl-xr) * (yu-yd));
            if (points[j].y < points[i].y) yd = max(yd, points[j].y);
            else yu = min(yu, points[j].y);
        }
    }
    sort(points + 1, points + n + 1, [](P a, P b){
        return a.y == b.y ? a.x < b.x : a.y < b.y;
    });
    for (int i = 1; i <= n-1; i++)
    {
        ans = max(ans, L * (points[i+1].y - points[i].y));
    }
    cout << ans;
    return 0;
}