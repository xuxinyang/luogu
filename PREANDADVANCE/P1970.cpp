#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, h[maxn], f[maxn], g[maxn];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    f[1] = g[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (h[i] > h[i-1]) f[i] = g[i-1]+1;
        else f[i] = f[i-1];
        if (h[i] < h[i-1]) g[i] = f[i-1]+1;
        else g[i] = g[i-1];
    }
    cout << max(f[n], g[n]);
    return 0;
}