#include <bits/stdc++.h>
using namespace std;
int n, a[105], minx1 = 105, minx2 = 105;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        minx1 = min(minx1, a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (minx2 > a[i] && a[i] > minx1)
            minx2 = a[i];
    }
    if (minx2 == 105) cout << "NO";
    else cout << minx2;
    return 0;
}