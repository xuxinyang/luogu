#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
int n, a[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        if ((n - i + 1) % 2)
            a[i] = !a[i];
    if (n % 2)
    {
        for (int i = n; i >= 1; i -= 2)
            cout << a[i] << " ";
        for (int i = 2; i <= n - 1; i += 2)
            cout << a[i] << " ";
    }
    else
    {
        for (int i = n; i >= 2; i -= 2)
            cout << a[i] << " ";
        for (int i = 1; i <= n - 1; i += 2)
            cout << a[i] << " ";
    }
    return 0;
}