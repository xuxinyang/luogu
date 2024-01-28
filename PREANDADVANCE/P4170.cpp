#include <bits/stdc++.h>
using namespace std;
char s[55];
int f[55][55], n;
int main()
{
    cin >> (s+1);
    n = strlen(s+1);
    memset(f, 0x7f, sizeof(f));
    for (int i = 1; i <= n; i++) f[i][i] = 1;
    for (int d = 1; d < n; d++)
    {
        for (int i = 1, j = d + 1; j <= n; ++i, ++j)
        {
            if (s[i] == s[j]) f[i][j] = min(f[i+1][j], f[i][j-1]);
            else
                for (int k = i; k < j; k++)
                    f[i][j] = min(f[i][j], f[i][k] + f[k+1][j]);
        }
    }
    cout << f[1][n];
    return 0;
}