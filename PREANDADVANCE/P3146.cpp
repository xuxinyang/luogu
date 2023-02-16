#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 255;
int n, val, ans;
int f[maxn][maxn];

int main()
{
    cin >> n;
    for (register int i = 1; i <= n; i++)
        cin >> val, f[i][i] = val;
    for (register int len = 2; len <= n; len++)
    {
        for (register int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            for (register int pos = i; pos < j; pos++)
            {
                if (f[i][pos] == f[pos + 1][j] && f[i][pos] != 0 && f[pos + 1][j] != 0)
                {
                    f[i][j] = max(f[i][j], f[i][pos] + 1);
                    ans = max(ans, f[i][pos] + 1);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}