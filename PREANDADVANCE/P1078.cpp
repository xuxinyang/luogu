#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int c[105], n;
int a[105][105];
int f[105][105];
bool used[105][105][105];
void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (!a[c[k]][c[i]] && !a[c[j]][c[k]] && !used[i][k][c[j]] && !used[k][j][c[i]] && f[i][k] + f[k][j] < f[i][j])
                {
                    for (int t = 1; t <= n; t++)
                        used[i][j][t] = used[i][k][t] || used[k][j][t];
                    used[i][j][c[k]] = true;
                    f[i][j] = f[i][k] + f[k][j];
                }
}
int main()
{
    memset(f, 0x3f, sizeof(f));
    int k, m, s, t, u, v, w;
    scanf("%d%d%d%d%d", &n, &k, &m, &s, &t);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &c[i]);
        f[i][i] = 0;
    }
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= k; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        if (!a[c[v]][c[u]] && c[u] != c[v])
            f[u][v] = min(w, f[u][v]);
        if (!a[c[u]][c[v]] && c[u] != c[v])
            f[v][u] = min(w, f[v][u]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            used[i][j][c[i]] = used[i][j][c[j]] = true;
        }
    floyd();
    if (f[s][t] == inf)
        printf("-1\n");
    else
        printf("%d\n", f[s][t]);
    return 0;
}