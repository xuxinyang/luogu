#include <bits/stdc++.h>
using namespace std;
constexpr int N = 505;
int n, l, x[N], y[N], p, fa[N];
struct Edge{
    int u, v;
    double d;
} e[N*N];
int find(int x)
{
    if (x == fa[x]) return x;
    else return fa[x] = find(fa[x]);
}
void merge(int u, int v)
{
    int fx = find(u), fy = find(v);
    if (fx != fy) fa[fy] = fx;
}
double dist(int p, int q)
{
    return sqrt(pow(x[p]-x[q], 2)+pow(y[p]-y[q], 2));
}
int main()
{
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if (dist(i, j) <= l)
                e[++p] = {i, j, dist(i, j)};
        }
    }
    sort(e+1, e+p+1, [](Edge A, Edge B){
        return A.d < B.d;
    });
    double s = 0;
    int t = 0;
    if (n == 1)
    {
        cout << "0.00";
        return 0;
    }
    for (int i = 1; i <= p; i++)
    {
        int u = e[i].u, v = e[i].v;
        double d = e[i].d;
        if (find(u) != find(v))
        {
            merge(u, v);
            s += d;
            t++;
            if (t == n-1)
            {
                printf("%.2lf", s);
                return 0;
            }
        }
    }
    cout << "Impossible";
    return 0;
}