#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const int maxn = 1e3+5;
int n, m, d[maxn], c[maxn], f[maxn][maxn];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i <= m; i++) cin >> c[i];
    memset(f, 0x7f, sizeof(f));
    for (int i = 0; i <= m; i++) f[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= m; j++)
        {
            f[i][j] = min(f[i][j-1], f[i-1][j-1]+d[i]*c[j]);
        }
    }
    cout << *min_element(f[n]+n+1, f[n]+m+1) << endl;;
    return 0;
}