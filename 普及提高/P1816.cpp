#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int m, n, a[maxn], f[maxn][16];

// ST表创建
void st_create()
{
    for (int i = 1; i <= m; i++) f[i][0] = a[i];
    int k = log2(m);
    for (int j = 1; j <= k; j++)
    {
        for (int i = 1; i <= m-(1<<j)+1; i++)
        {
            f[i][j] = min(f[i][j-1], f[i+(1<<(j-1))][j-1]);
        }
    }
}

// ST表查询
int st_query(int l, int r)
{
    int k = log2(r-l+1);
    return min(f[l][k], f[r-(1<<k)+1][k]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l, r;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) cin >> a[i];
    st_create();
    while (n--)
    {
        cin >> l >> r;
        cout << st_query(l, r) << " ";
    }
    return 0;
}