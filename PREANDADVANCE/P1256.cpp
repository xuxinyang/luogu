#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int n;;
double x[5010], y[5010], dis[5010], book[5010], ans;

double get_e(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void init()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%lf", &x[i], &y[i]);
        dis[i] = 1e12 * 1.0;
    }
    return;
}

void Prim()
{
    dis[1] = 0.0;
    book[1] = true;
    int curr;
    double minn;
    for (int i = 1; i <= n; i++)
    {
        curr = 1;
        minn = 1e9 * 1.0;
        for (int j = 1; j <= n; j++)
            if (!book[j] && dis[j] < minn)
                minn = dis[j], curr = j;
        book[curr] = true;
        ans += dis[curr];
        for (int j = 1; j <= n; j++)
            dis[j] = min(dis[j], get_e(x[curr], y[curr], x[j], y[j]));
    }
    printf("%.2lf", ans);
    return;
}

int main()
{
    init();
    Prim();
    return 0;
}