#include <bits/stdc++.h>
using namespace std;
int n, m, f[35][35];
int main()
{
    cin >> n >> m;
    f[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (f[i][j])
            {
                f[i+1][(j-1+n)%n] += f[i][j];
                f[i+1][(j+1)%n] += f[i][j];
            }
        }
    }
    cout << f[m][0];
    return 0;
}