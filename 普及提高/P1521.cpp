#include <bits/stdc++.h>
using namespace std;
int n, k, f[5005][5005];
int main()
{
    cin >> n >> k;
    f[1][0] = f[2][1] = f[2][0] = f[0][0] = 1;
    for (int i = 3; i <= n; i++)
        for (int j = 0; j <= k; j++)
            for (int k = 0; k <= i - 1 && j - k >= 0; k++)
                f[i][j] = (f[i-1][j-k] + f[i][j]) % 10000;
    cout << f[n][k] << endl;
    return 0;
}