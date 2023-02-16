#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int maxm = 1e6+5;
int fa[maxn], a[maxn], b[maxn], s, p, cnt, k;
double ans;
struct Edge
{
    double x, y, z;
};
Edge edges[maxm];
bool cmp(Edge e1, Edge e2)
{
    return e1.z < e2.z;
}
int find(int x)
{
    return x == fa[x] ? x : find(fa[x]);
}
void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    fa[fy] = fx;
}
int main()
{
    cin >> s >> p;
    for (int i = 1; i <= p; i++)
    {
        cin >> a[i] >> b[i];
        for (int j = 1; j < i; j++)
        {
            edges[++cnt].z = sqrt(pow(a[i]-a[j], 2) + pow(b[i]-b[j], 2));
            edges[cnt].x = i;
            edges[cnt].y = j;
        }
    }
    for (int i = 1; i <= p; i++) fa[i] = i;
    sort(edges + 1, edges + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i++)
    {
        if (find(edges[i].x) != find(edges[i].y))
        {
            merge(edges[i].x, edges[i].y);
            ans = edges[i].z;
            k++;
            if (k >= p - s)
            {
                cout << fixed << setprecision(2) << ans << endl;
                return 0;
            }
        }
    }
    return 0;
}