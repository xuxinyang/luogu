#include <bits/stdc++.h>
using namespace std;
long long f[21], g[21];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 2 * g[i-1] + 1;
        g[i] = 2 * g[i-1] + f[i-1] + 2;
    }
    cout << g[n];
    return 0;
}