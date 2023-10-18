#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    for (; !isalnum(ch); ch = getchar())
        if (ch == '-')
            f = -1;
    for (; isalnum(ch); ch = getchar())
        x = x * 10 + ch - '0';
    return x * f;
}
const int xx = 52;
struct point
{
    int x, y;
} d[xx], e[xx];
int ans = 0x7fffffff, n;
inline bool cmp1(point a, point b) { return a.x < b.x; }
inline bool cmp2(point a, point b) { return a.y < b.y; }
inline int div(int d1, int d2, int e1, int e2, int k)
{
    int res = ans;
    if (k)
    {
        for (register int i = d1; i < d2; ++i)
            for (register int j = 0; j < k; ++j)
                res = min(res, div(d1, i, e1, e2, k - j - 1) + div(i + 1, d2, e1, e2, j));
        for (register int i = e1; i < e2; ++i)
            for (register int j = 0; j < k; ++j)
                res = min(res, div(d1, d2, e1, i, k - j - 1) + div(d1, d2, i + 1, e2, j));
        return res;
    }
    int mxx = 0, mnx = ans, mxy = 0, mny = ans;
    for (register int i = 1; i <= n; ++i)
        if (d[i].x >= d[d1].x && d[i].x <= d[d2].x)
            if (d[i].y >= e[e1].y && d[i].y <= e[e2].y)
                mxx = d[i].x, mnx = min(mnx, d[i].x), mxy = max(mxy, d[i].y), mny = min(mny, d[i].y);
    return (mxy - mny) * (mxx - mnx);
}
int main()
{
    n = read();
    int k = read();
    for (register int i = 1; i <= n; i++)
        d[i] = e[i] = (point){read(), read()};
    sort(d + 1, d + n + 1, cmp1);
    sort(e + 1, e + n + 1, cmp2);
    ans = div(1, n, 1, n, k - 1);
    printf("%d\n", ans);
    return 0;
}