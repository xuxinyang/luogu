#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, m, ans[maxn], f[maxn], fa[maxn];

int find(int x)
{
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) f[fy] = f[fx]; 
}
void search(int p, int q)
{
    if (find(p) == find(q))
    {
        int cnt = 1;
        for (int i = p; i != q; i = fa[i]) cnt++;
        for (int i = p; i != q; i = fa[i]) ans[i] = cnt;
        ans[q] = cnt;
        return;
    }
    merge(p, q);
    fa[q] = p;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        search(m, i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!ans[i]) 
        {
            int cnt = 1, j;
            for (j = fa[i]; !ans[j]; j = fa[j]) cnt++;
            ans[i] = cnt + ans[j];
        }
        cout << ans[i] << "\n";
    }
    return 0;
}