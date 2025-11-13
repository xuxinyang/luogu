#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int maxm = 1e5+5;
int n, m, fa[maxn], cnt;
int find(int x)
{
    if (x != fa[x]) return fa[x] = find(fa[x]);
    else return x;
}
void merge(int u, int v)
{
    if (find(u) == find(v)) return;
    int fx = find(u), fy = find(v);
    if (fx != fy) fa[fx] = fy;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (find(u) != find(v)) 
        {
            merge(u, v);
            cnt++;
        }
    }
    cout << n-1 - cnt;
    return 0;
}