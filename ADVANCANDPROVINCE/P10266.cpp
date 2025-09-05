#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int maxn = 3e3+5;
const int B = 1e3+5;
const int maxm = 1e6+5;
ll n, m, k, v[maxn][maxn];
ll a[maxn][maxn], b[maxn][maxn], sa[maxn][maxn], sb[maxn][maxn], S[maxn][maxn];
signed main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> v[i][j];
    for (int i = 1, x, y, p; i <= k; i++)
    {
        cin >> x >> y >> p;
        p--;
        x += B, y += B;
        sa[x - p][y - p] += 1;
        a[x - p + 1][y - p + 1] += 2;
        a[x + 1][y + 1] -= 2;
        a[x + 2][y + 2] -= 2;
        a[x + p + 2][y + p + 2] += 2;
        sa[x + p + 2][y + p + 2] -= 1;
        sb[x - p][y + p + 1] -= 1;
        b[x - p + 1][y + p] -= 2;
        b[x + 1][y] += 2;
        b[x + 2][y - 1] += 2;
        b[x + p + 2][y - p - 1] -= 2;
        sb[x + p + 2][y - p - 1] += 1;
    }
    for (int i = 1; i < maxn; i++)
        for (int j = 1; j < maxn; j++)
            a[i][j] += a[i - 1][j - 1];
    for (int i = 1; i < maxn; i++)
        for (int j = 1; j < maxn; j++)
            sa[i][j] = sa[i][j] + a[i][j] + sa[i - 1][j - 1];
    for (int i = 1; i < maxn; i++)
        for (int j = maxn - 2; j >= 0; j--)
            b[i][j] += b[i - 1][j + 1];
    for (int i = 1; i < maxn; i++)
        for (int j = maxn - 2; j >= 0; j--)
            sb[i][j] = sb[i][j] + b[i][j] + sb[i - 1][j + 1];
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            S[i][j] += sb[i][j];
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            S[i][j] += sa[i][j];
    for (int i = 1; i < maxn; i++)
        for (int j = 1; j < maxn; j++)
            S[i][j] += S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
    for (int i = 1; i <= n; i++, cout << endl)
        for (int j = 1; j <= m; j++)
            cout << max(0ll, v[i][j] - S[i + B][j + B]) << ' ';
    return 0;
}
