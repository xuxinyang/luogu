#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
int n, m, w, fa[maxn], c[maxn], d[maxn], f[maxn];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy) fa[fy] = fx;
}
int main()
{
    cin >> n >> m >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i] >> d[i];
        fa[i] = i;
    }
    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        if (find(x) != find(y)) merge(x, y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (fa[i] != i)
        {
            // 祖先相同则属于同一个块
            d[find(i)] += d[i], d[i] = 0;
            c[find(i)] += c[i], c[i] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = w; j >= c[i]; j--)
        {
            f[j] = max(f[j], f[j-c[i]] + d[i]);
        }
    }
    cout << f[w];
    return 0;
}