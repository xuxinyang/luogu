#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, f[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
        for (int j = 1; j <= sqrt(i); j++)
        {
            f[i] = min(f[i-j*j]+1, f[i]);
        }
    }
    cout << f[n];
    return 0;
}