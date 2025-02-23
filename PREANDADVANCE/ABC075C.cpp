#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const int M = N*N/2;
struct Edge
{
    int u, v;
};
Edge edges[M];
int n, m, cnt, fa[N];
int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int u, int v)
{
    int fu = find(u), fv = find(v);
    if (fu != fv) fa[fu] = fv;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> edges[i].u >> edges[i].v;
    }
    for (int i = 1; i <= m; i++)
    {
        memset(fa, 0, sizeof(fa));
        for (int j = 1; j <= n; j++) fa[j] = j;
        for (int j = 1; j <= m; j++)
        {
            if (i == j) continue;
            merge(edges[j].u, edges[j].v);
        }
        int u = edges[i].u, v = edges[i].v;
        if (find(u) != find(v)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}