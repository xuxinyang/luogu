#include <bits/stdc++.h>
using namespace std;
int n, f[55][55], root[55][55];
void order(int l, int r)
{
    if (l > r) return;
    cout << root[l][r] << " ";
    order(l, root[l][r] - 1);
    order(root[l][r] + 1, r);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i][i];
        f[i][i-1] = 1, root[i][i] = i;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j + i <= n; j++)
        {
            int k = i + j;
            f[j][k] = f[j+1][k] + f[j][j];
            root[j][k] = j;
            for (int m = j + 1; m < k; m++)
            {
                if (f[j][k] < f[j][m-1] * f[m+1][k] + f[m][m])
                {
                    f[j][k] = f[j][m-1] * f[m+1][k] + f[m][m];
                    root[j][k] = m;
                }
            }
        }
    }
    cout << f[1][n] << endl;
    order(1, n);
    return 0;
}