#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int dx[9] = {0, -2, -2, -1, 1, 2, 2, 1, -1};
const int dy[9] = {0, -1, 1, 2, 2, 1, -1, -2, -2};
ll n, m, mx, my, f[25][25];
bool flag[25][25];
int main()
{
    cin >> n >> m >> mx >> my;
    n += 2, m += 2, mx += 2, my += 2;
    for (int i = 0; i < 9; i++)
    {
        // 马能够到达的位置
        int fx = mx + dx[i];
        int fy = my + dy[i];
        flag[fx][fy] = 1;
    }
    f[2][1] = 1; // f[1][2] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            if (flag[i][j]) f[i][j] = 0;
            else f[i][j] = f[i-1][j] + f[i][j-1];
        }
    }
    cout << f[n][m];
    return 0;
}