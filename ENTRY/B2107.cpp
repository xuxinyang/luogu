#include <bits/stdc++.h>
using namespace std;
int a[105][105], b[105][105];
int n, m;
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            b[i][j] = a[m-j+1][i];
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}