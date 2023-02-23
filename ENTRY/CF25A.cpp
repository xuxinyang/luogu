#include <bits/stdc++.h>
using namespace std;
int n, a[105], ans, odd, even;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0) even++;
        else odd++;
    }
    if (even > odd)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] % 2 == 1)
            {
                cout << i;
                break;
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] % 2 == 0)
            {
                cout << i;
                break;
            }
        }
    }
    return 0;
}