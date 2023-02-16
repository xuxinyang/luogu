#include <bits/stdc++.h>
using namespace std;
bool flag[20][20]; 
int f[20][20];
int a, b, n, x, y;
int main()
{
    cin >> a >> b;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        flag[x][y] = 1;
    }
    f[1][0] = 1;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (flag[i][j]) f[i][j] = 0;
            else f[i][j] = f[i-1][j] + f[i][j-1];
        }
    }
    cout << f[a][b] << endl;
    return 0;
}