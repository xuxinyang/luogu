#include <bits/stdc++.h>
using namespace std;
int maps[155][155];
struct Edge
{
    int x, y;
} E[5001];
int dfn[151], low[151], n, m, id, cnt, f[151];
bool cmp(Edge a, Edge b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
void addEdge(int x, int y)
{
    E[++cnt].x = x;
    E[cnt].y = y;
}
void tarjan(int x)
{
    int c = 0, y;
    dfn[x] = low[x] = ++id;
    for (register int i = 1; i <= n; i++)
    {
        if (!maps[x][i])
            continue;
        y = i;
        if (dfn[y] && y != f[x])
            low[x] = min(low[x], dfn[y]);
        if (!dfn[y])
        {
            f[y] = x;
            tarjan(y);
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x])
                addEdge(x, y);
        }
    }
}
int main()
{
    int x, y;
    cin >> n >> m;
    for (register int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        maps[x][y] = maps[y][x] = 1;
    }
    for (register int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }
    sort(E + 1, E + cnt + 1, cmp);
    for (register int i = 1; i <= cnt; i++)
    {
        cout << min(E[i].x, E[i].y) << ' ' << max(E[i].x, E[i].y) << endl; // 输出
    }
    return 0;
}
