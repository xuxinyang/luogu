#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e3+5;
const int dx[5] = {0, 0, 1, 0, -1};
const int dy[5] = {0, -1, 0, 1, 0};
int n, m, a[maxn][maxn], num[10];
ll ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            num[a[i][j]]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int sum = 0;
            for (int k = 0; k <= 4; k++)
            {
                int fx = i + dx[k], fy = j + dy[k];
                if (fx >= 1 && fx <= n && fy >= 1 && fy <= m && a[fx][fy] == a[i][j])
                    sum++;
            }
            ans += num[a[i][j]] - sum;
        }
    }
    cout << ans;
    return 0;
}