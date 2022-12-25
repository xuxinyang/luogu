#include <bits/stdc++.h>
using namespace std;
int n, f[205][205];
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> f[i][j];
        }
    }
    for (int d = 3; d <= n; d++)
    {
        for (int i = 1; i <= n-d+1; i++)
        {
            int j = i + d - 1;
            for (int k = i + 1; k < j; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
        }
    }
    cout << f[1][n] << endl;
    return 0;
}