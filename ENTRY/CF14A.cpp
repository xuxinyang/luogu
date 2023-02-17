#include <bits/stdc++.h>
using namespace std;
int n, m, l, r, u, d;
bool flag;
char a[55][55];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    // u
    for (int i = 1; i <= n; i++)
    {
        flag = 0;
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '*')
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            u = i;
            break;
        }
    }
    // d
    for (int i = n; i >= 1; i--)
    {
        flag = 0;
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '*')
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            d = i;
            break;
        }
    }
    // l
    for (int i = 1; i <= m; i++)
    {
        flag = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j][i] == '*')
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            l = i;
            break;
        }
    }
    // r
    for (int i = m; i >= 1; i--)
    {
        flag = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j][i] == '*')
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            r = i;
            break;
        }
    }
    // cout << l << " " << r << " " << u << " " << d << endl;
    for (int i = u; i <= d; i++)
    {
        for (int j = l; j <= r; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}