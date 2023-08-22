#include <bits/stdc++.h>
using namespace std;
string s;
int n, m, tot, res;
int b[100010], fa[100010], dis[100010];

struct node
{
    int u, v, op;
} a[100010];

inline int find(int x)
{
    if (fa[x] == x)
        return x;
    int root = find(fa[x]);
    dis[x] ^= dis[fa[x]];
    return fa[x] = root;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (register int i = 1; i <= m; i++)
    {
        scanf("%d%d", &a[i].u, &a[i].v);
        cin >> s;
        if (s == "even")
            a[i].op = 0;
        else
            a[i].op = 1;
        b[++tot] = a[i].u;
        b[++tot] = a[i].v;
    }
    sort(b + 1, b + 1 + tot);
    res = unique(b + 1, b + 1 + tot) - (b + 1);
    for (register int i = 1; i <= 2 * res; i++)
        fa[i] = i;
    for (register int i = 1; i <= m; i++)
    {
        int x = lower_bound(b + 1, b + 1 + res, a[i].u - 1) - b;
        int y = lower_bound(b + 1, b + 1 + res, a[i].v) - b;
        int xx = find(x), yy = find(y);
        if (xx == yy)
        {
            if ((dis[x] ^ dis[y]) != a[i].op)
            {
                printf("%d", i - 1);
                return 0;
            }
        }
        else
        {
            fa[xx] = yy;
            dis[xx] = dis[x] ^ dis[y] ^ a[i].op;
        }
    }
    printf("%d", m);
    return 0;
}