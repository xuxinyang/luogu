#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
const int maxc = 1e4+5;
int v, n, c, k[maxn], m[maxn], f[maxc], t;
int main()
{
    cin >> v >> n >> c;
    for (int i = 1; i <= n; i++) cin >> k[i] >> m[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = c; j >= m[i]; j--)
        {
            f[j] = max(f[j], f[j-m[i]]+k[i]);
        }
    }
    if (v > f[c]) cout << "Impossible";
    else
    {
        t = c;
        while (f[t] >= v) t--;
        t++;
        cout << c - t;
    }
    return 0;
}