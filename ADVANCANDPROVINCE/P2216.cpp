#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const int maxn = 1e3 + 5;
int a, b, n, nums[maxn][maxn];
int logn, maxv[maxn][maxn], minv[maxn][maxn], ans;
int query(int x, int y)
{
    int maxx = 0, minx = 0;
    maxx = max(max(maxv[x][y], maxv[x + n - (1 << logn)][y + n - (1 << logn)]),
               max(maxv[x + n - (1 << logn)][y], maxv[x][y + n - (1 << logn)]));
    minx = min(min(minv[x][y], minv[x + n - (1 << logn)][y + n - (1 << logn)]),
               min(minv[x + n - (1 << logn)][y], minv[x][y + n - (1 << logn)]));
    return maxx - minx;
}
int main()
{
    cin >> a >> b >> n;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            cin >> nums[i][j];
            maxv[i][j] = minv[i][j] = nums[i][j];
        }
    }
    logn = log(n) / log(2);
    for (int k = 0; k <= logn-1; k++)
    {
        for (int i = 1; i + (1 << k) <= a; i++)
        {
            for (int j = 1; j + (1 << k) <= b; j++)
            {
                maxv[i][j] = max(max(maxv[i][j], maxv[i + (1 << k)][j + (1 << k)]),
                                 max(maxv[i + (1 << k)][j], maxv[i][j + (1 << k)]));
                minv[i][j] = min(min(minv[i][j], minv[i + (1 << k)][j + (1 << k)]),
                                 min(minv[i + (1 << k)][j], minv[i][j + (1 << k)]));
            }
        }
    }
    ans = inf;
    for (int i = 1; i <= a - n + 1; i++)
    {
        for (int j = 1; j <= b - n + 1; j++)
        {
            ans = min(ans, query(i, j));
        }
    }
    cout << ans;
    return 0;
}