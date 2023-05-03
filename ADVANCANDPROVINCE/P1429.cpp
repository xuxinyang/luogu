#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
const int inf = 2 << 20;
int n, temp[maxn];
struct Point
{
    double x, y;
};
Point points[maxn];
bool cmp(const Point &a, const Point &b)
{
    if (a.x == b.x) return a.y < b.y;
    else return a.x < b.x;
}
bool cmps(const int a, const int b) { return points[a].y < points[b].y; }
double dist(int x, int y)
{
    return sqrt(pow(points[x].x - points[y].x, 2) + pow(points[x].y - points[y].y, 2));
}
double merge(int l, int r)
{
    double d = inf;
    if (l == r) return d;
    if (l + 1 == r) return dist(l, r);
    int mid = (l + r) >> 1;
    double d1 = merge(l, mid);
    double d2 = merge(mid + 1, r);
    d = min(d1, d2);
    int i, j, k = 1;
    for (i = l; i <= r; i++)
        if (fabs(points[mid].x - points[i].x) < d)
            temp[k++] = i;
    sort(temp + 1, temp + k, cmps);
    for (i = 1; i < k; i++)
        for (j = i + 1; j < k && points[temp[j]].y - points[temp[i]].y < d; j++)
        {
            double d3 = dist(temp[i], temp[j]);
            if (d > d3) d = d3;
        }
    return d;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &points[i].x, &points[i].y);
    sort(points + 1, points + n + 1, cmp);
    return !printf("%.4lf\n", merge(1, n));
}