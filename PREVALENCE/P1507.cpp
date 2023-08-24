#include <bits/stdc++.h>
using namespace std;
const int maxh = 405;
const int maxt = 405;
const int maxn = 55;
int h, t, n, v[maxn], w[maxn], k[maxn];
int f[maxh][maxt];
int main()
{
    cin >> h >> t >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> k[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = h; j >= v[i]; j--)
        {
            for (int o = t; o >= w[i]; o--)
            {
                f[j][o] = max(f[j][o], f[j-v[i]][o-w[i]] + k[i]);
            }
        }
    }
    cout << f[h][t];
    return 0;
}