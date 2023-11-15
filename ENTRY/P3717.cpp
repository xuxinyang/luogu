#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, m, r, ans, a[maxn][maxn];
double dist(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}
int main()
{
    int x, y;
    cin >> n >> m >> r;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        for (int j = max(1, x-r); j <= min(n, x+r); j++)
        {
            for (int k = max(1, y-r); k <= min(n, y+r); k++)
            {
                if (dist(x, y, j, k) <= r) a[j][k] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j]) ans++;
        }
    }
    cout << ans;
    return 0;
}