#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
const int maxl = 1005;
int n, beginLevel, maxLevel, v[maxn], f[maxn][maxl];
// f[i][j]表示前i首歌曲是否能够到达音调j
int main()
{
    cin >> n >> beginLevel >> maxLevel;
    for (int i = 1; i <= n; i++) cin >> v[i];
    f[0][beginLevel] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = maxLevel; j >= 0; j--)
        {
            if (j - v[i] >= 0)
                f[i][j] = f[i][j] | f[i-1][j-v[i]];
            if (j + v[i] < maxLevel)
                f[i][j] = f[i][j] | f[i-1][j+v[i]];
        }
    }
    int t = maxLevel;
    while (f[n][t] == 0 && t > 0) t--;
    if (t == 0) cout << -1;
    else cout << t;
    return 0;
}