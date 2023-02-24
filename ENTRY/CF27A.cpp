#include <bits/stdc++.h>
using namespace std;
int n, x, a[3005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[x] = 1;
    }
    for (int i = 1; i <= 3004; i++)
    {
        if (a[i] == 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}