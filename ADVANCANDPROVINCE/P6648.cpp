#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e3 + 5;
int n, k;
int st[maxn][maxn][2], logn;
ll ans;
void st_init()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> st[i][j][0];
        }
    }
}
int st_query(int x, int y)
{
    int l = x + k - 1, r = y + k - 1;
    int u = logn & 1;
    int ans = max(st[x][y][u],
                  max(st[l - (1 << logn) + 1][y][u], st[l - (1 << logn) + 1][r - (1 << logn) + 1][u]));
    if (logn <= 1)
        return ans;
    int p = (k - (1 << logn)) >> 1;
    ans = max(max(ans, st[l - (1 << logn) + 1][y + p][u]), max(st[x + p][y][u], st[x + p][y + p][u]));
    return ans;
}
int main()
{
    cin >> n >> k;
    st_init();
    logn = log2(k);
    for (int t = 1; t <= logn; t++)
    {
        int u = t & 1, v = u ^ 1;
        for (int i = 1; i + (1 << t) - 1 <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                st[i][j][u] = max(max(st[i][j][v], st[i + (1 << (t - 1))][j][v]),
                                  st[i + (1 << (t - 1))][j + (1 << (t - 1))][v]);
                if (t > 1)
                    st[i][j][u] = max(max(st[i][j][u], st[i + (1 << (t - 1))][j + (1 << (t - 2))][v]),
                                      max(st[i + (1 << (t - 2))][j][v], st[i + (1 << (t - 2))][j + (1 << (t - 2))][v]));
            }
        }
    }
    for (int i = 1; i <= n - k + 1; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            ans += st_query(i, j);
        }
    }
    cout << ans;
    return 0;
}