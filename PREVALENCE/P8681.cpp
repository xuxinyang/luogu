#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 5;
const int maxm = 25;
ll n, a[maxn], dep[maxm], maxx;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int p = 0, k = 0;
    while (p <= n)
    {
        for (int i = 1; i <= (1 << k) && p <= n; i++)
        {
            dep[k + 1] += a[++p];
        }
        maxx = max(maxx, dep[++k]);
    }
    for (int i = 1; i <= log2(n) + 1; i++)
    {
        if (maxx == dep[i])
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}