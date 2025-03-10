#include <bits/stdc++.h>
using namespace std;
int c, f1, f2, d, f[2005];
int main()
{
    cin >> c >> f1 >> f2 >> d;
    for (int i = 1; i <= c; i++)
    {
        int l, r;
        cin >> l >> r;
        f[l]++, f[r+1]--;
    }
    for (int i = 1; i <= d; i++)
    {
        f[i] += f[i-1];
    }
    for (int i = d; i >= 1; i--)
    {
        f2 += f[i];
        if (f2 == f1)
        {
            cout << i;
            break;
        }
    }
    return 0;
}