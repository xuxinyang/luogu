#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5+5;
const int maxq = 5e5+5;
int n, m, q, k, op, x;
int row[maxn], col[maxn], r[maxq], c[maxq];
ll ans, ansr, ansc;
int main()
{
    cin >> n >> m >> q >> k;
    while (q--)
    {
        cin >> op >> x;
        if (op == 1) row[x]++, row[x] %= k;
        else col[x]++, col[x] %= k;
    }
    for (int i = 1; i <= n; i++)
    {
        if (row[i]) ansr++, r[row[i]]++;
    }
    for (int i = 1; i <= m; i++)
    {
        if (col[i]) ansc++, c[col[i]]++;
    }
    ans = ansr * m + ansc * n - ansc * ansr;
    int i = 1, j = k-1;
    while (i <= k-1 && j >= 1)
    {
        ans -= 1ll* r[i] * c[j];
        i++, j--;
    }
    cout << ans;
    return 0;
}