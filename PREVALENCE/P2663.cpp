#include <bits/stdc++.h>
using namespace std;
int n, a[105], f[105][10005], k;
int main()
{
    int sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sum /= 2;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            for (int k = sum; k >= a[i]; k--)
                f[j][k] |= f[j-1][k-a[i]];
        }
    }
    for (int i = sum; i >= 0; i--) 
        if (f[n/2][i])
        {
            cout << i << endl;
            return 0;
        }
    return 0;
}