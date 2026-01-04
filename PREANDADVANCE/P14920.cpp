#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 505;
const int M = N*N;
ll n, k, a[N], c[N], f[M], s;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i] >> c[i], s += a[i];
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = s; j >= a[i]; j--)
        {
            f[j] = min(f[j], f[j-a[i]]+c[i]);
        }
    }
    for (int i = s; i >= 0; i--)
    {
        if (f[i] <= k)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}