#include <bits/stdc++.h>
#define MAXN 10005
#define MAXM 100005
using namespace std;
int d[MAXN], u[MAXM], v[MAXM];
int main()
{
    int n, i, m;
    long long ans = 0;
    scanf("%d%d", &n, &m);
    memset(d, 0, sizeof(d));
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &u[i], &v[i]);
        d[u[i]]++;
        d[v[i]]++;
    }
    for (i = 0; i < m; i++)
    {
        if (d[u[i]] > 1 && d[v[i]] > 1)
            ans += (d[u[i]] - 1) * (d[v[i]] - 1) * 2;
    }
    cout << ans;
    return 0;
}