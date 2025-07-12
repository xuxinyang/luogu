#include <bits/stdc++.h>
using namespace std;
int a, b, n, m, cnt;
int main()
{
    cin >> n >> m >> a >> b;
    if (n > m) swap(n, m);
    if (a > b) swap(a, b);
    while (n>=a&&m>=b||n>=b&&m>=a)
    {
        n -= a, m -= b;
        cnt++;
        if (n > m) swap(n, m);
    }
    cout << cnt;
    return 0;
}