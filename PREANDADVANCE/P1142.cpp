#include <bits/stdc++.h>
using namespace std;
const int maxn = 706;
int n, ans, idx;
struct Point
{
    int x, y;
};
struct Line
{
    int x2, y2, dx, dy;
};
Point p[maxn];
Line l[maxn*maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    sort(p + 1, p + n + 1, [](Point A, Point B)
         { return A.x == B.x ? A.y < B.y : A.x < B.x; });
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            l[++idx] = Line{p[j].x, p[j].y, p[j].x-p[i].x, p[j].y-p[i].y};
        }
    }
    for (int i = 1; i <= idx; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if ((p[j].y-l[i].y2)*l[i].dx == (p[j].x-l[i].x2)*l[i].dy) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}