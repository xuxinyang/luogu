#include <bits/stdc++.h>
using namespace std;
int n, m, fa[10005];
int find(int x)
{
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
        fa[fy] = fx;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    int op, x, y;
    while (m--)
    {
        cin >> op >> x >> y;
        if (op == 1)
        {
            merge(x, y);
        }
        else
        {
            if (find(x) != find(y)) cout << "N\n";
            else cout << "Y\n";
        }
    }
    return 0;
}