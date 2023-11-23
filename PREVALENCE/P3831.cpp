#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+5;
const int maxm = 1e3+5;
ll n, x, y, p, q, k;
ll a[maxn], b[maxn], ans[maxm];
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> x >> y >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    for (int i = 1; i <= p; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[j] = (a[j] * x + y) % p;
            if (a[j] == b[j]) ans[i]++;
        }
    }
    ans[0] = ans[p];
    cin >> q;
    while (q--)
    {
        cin >> k;
        cout << ans[k % p] << "\n";
    }
    return 0;
}