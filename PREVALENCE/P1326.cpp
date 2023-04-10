#include <bits/stdc++.h>
using namespace std;
long long s, t, n, mx, mi;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> s >> t >> n)
    {
        mx = mi = 0;
        if (s < n)
        {
            mx += s * 3;           // win
            mx += n - s - 1;       // draw
            if (!t) mx += 1;        // draw
        }
        else 
        {
            mx += (n - 1) * 3;      // win
            if (s - (n-1) > t) mx += 3; // win
            else if (s - (n-1) == t) mx += 1;   // draw
        }
        cout << mx << " ";
        if (s > t)
        {
            mi += 3;    // win 1
            if (t >= n - 1) ; // loss
            else mi += n - 1  - t;

        }
        else
        {
            long long x = 3, y = 0;
            if (t - s >= n);
            else y = n - (t - s);
            if (t < n - 1) x += n - 1 - t;
            mi = min(x, y);
        }
        cout << mi << "\n";
    }
    return 0;
}