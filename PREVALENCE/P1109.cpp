#include <bits/stdc++.h>
using namespace std;
int n, a[55], l, r, sum, low, high;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    cin >> l >> r;
    if (sum > n * r || sum < n * l)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < l) low += (l - a[i]);
        if (a[i] > r) high += (a[i] - r); 
    }
    cout << max(low, high) << endl;
    return 0;
}