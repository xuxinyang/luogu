#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, m, res[maxn][2], cnt, ci;
double eps = 1e-10, R;
struct Point
{
    double x, y;
};
Point a[maxn], b[maxn], tmp;
Point getMid(Point A, Point B)
{
    return (Point){(A.x+B.x)/2, (A.y+B.y)/2};
}
double dist(Point A, Point B)
{
    return sqrt(pow(A.x-B.x,2) + pow(A.y-B.y, 2));
}
void getTmp(Point A, Point B, Point C)
{
    double aa, bb, cc, dd, ee, ff;
    aa = A.x - C.x, bb = A.y - C.y;
    cc = B.x - C.x, dd = B.y - C.y;
    ee = A.x * A.x + A.y * A.y - C.x * C.x - C.y * C.y;
    ff = B.x * B.x + B.y * B.y - C.x * C.x - C.y * C.y;
    tmp.x = (dd * ee - bb * ff) / (2 * aa * dd - 2 * bb * cc);
    tmp.y = (aa * ff - cc * ee) / (2 * aa * dd - 2 * bb * cc);
    R = dist(tmp, A);
}
void work(int l, int r)
{
    int tot = 0;
    for (int i = l; i <= r; i++) b[++tot] = a[i];
    for (int i = 1; i <= tot; i++) swap(b[i], b[rand()%tot+1]);
    tmp = b[1];
    R = 0;
    for (int i = 1; i <= tot; i++)
    {
        if (dist(b[i], tmp) > R + eps)
        {
            tmp = b[i], R = 0;
            for (int j = 1; j < i; j++)
            {
                if (dist(b[j], tmp) > R + eps)
                {
                    tmp = getMid(b[i], b[j]);
                    R = dist(tmp, b[i]);
                    for (int k = 1; k < j; k++)
                    {
                        if (dist(b[k], tmp) > R + eps)
                        {
                            getTmp(b[i], b[j], b[k]);
                        }
                    }
                }
            }
        }
    }

}
bool check(double lim)
{
    cnt = 0;
    int ans;
    for (int i = 1; i <= n; i = ans+1)
    {
        int k;
        for (k = 1; i + (1<<k)-1 <= n; k++)
        {
            work(i, i+(1<<k)-1);
            if (R > lim + eps) break;
        }
        ans = i;
        int l = i + (1<<(k-1))-1, r = min(n, i+(1<<k)-1);
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            work(i, mid);
            if (R < lim + eps) l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        cnt++;
        res[cnt][0] = i, res[cnt][1] = ans;
        if (cnt > m) return 0;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    work(1, n);
    double l = 0, r = R;
    if (m > 1)
    {
        ci = 50;
        while (ci-- && r - l > eps)
        {
            double mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid;
        }
    }
    check(r);
    cout << fixed << setprecision(8) << r << "\n";
    cout << cnt << "\n";
    for (int i = 1; i <= cnt; i++)
    {
        work(res[i][0], res[i][1]);
        cout << fixed << setprecision(8) << tmp.x << " " << tmp.y << "\n";
    }
    return 0;
}