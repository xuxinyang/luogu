#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
int n, f[maxn][maxn][maxn][maxn][maxn], a, b, c, d, e, ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c >> d >> e;
        // 转动一个拨轮
        for (int j = 0; j <= 9; j++) f[j][b][c][d][e]++;
        for (int j = 0; j <= 9; j++) f[a][j][c][d][e]++;
        for (int j = 0; j <= 9; j++) f[a][b][j][d][e]++;
        for (int j = 0; j <= 9; j++) f[a][b][c][j][e]++;
        for (int j = 0; j <= 9; j++) f[a][b][c][d][j]++;
        // 转动两个拨轮
        for (int j = 0; j <= 9; j++) f[(a+j)%10][(b+j)%10][c][d][e]++;
        for (int j = 0; j <= 9; j++) f[a][(b+j)%10][(c+j)%10][d][e]++;
        for (int j = 0; j <= 9; j++) f[a][b][(c+j)%10][(d+j)%10][e]++;
        for (int j = 0; j <= 9; j++) f[a][b][c][(d+j)%10][(e+j)%10]++;
    }
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                for (int p = 0; p <= 9; p++)
                    for (int q = 0; q <= 9; q++)
                        if (f[i][j][k][p][q] == n)
                        {
                            // printf("%d %d %d %d %d\n", i, j, k, p, q);
                            ans++;
                        }
    cout << ans;
    return 0;
}