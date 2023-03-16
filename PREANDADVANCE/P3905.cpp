#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int maxm = 10005;
const int inf = 0x3f3f3f3f;
int n, m, d, a, b, f[maxn][maxn];
bool flag[maxn][maxn];
int main()
{
    int x, y, z;
    cin >> n >> m;
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++) f[i][i] = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> z;
        f[x][y] = f[y][x] = z;
    }
    cin >> d;
    for (int i = 1; i <= d; i++)
    {
        cin >> x >> y;
        flag[x][y] = flag[y][x] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (f[i][j] != inf && flag[i][j] == 0)
            {
                f[i][j] = 0;
            }
        }
    }
    cin >> a >> b;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (f[i][k] + f[k][j] < f[i][j])
                {
                    f[i][j] = f[i][k] + f[k][j];
                }
            }
        }
    }
    cout << f[a][b];
    return 0;
}