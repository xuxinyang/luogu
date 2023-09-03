#include <bits/stdc++.h>
using namespace std;
int t, p, x, y, k1, k2;
int main()
{
    cin >> t >> p;
    while (t--)
    {
        cin >> x >> y;
        k1 = x, k2 = y;
        while (true)
        {
            x = (x + y) % p;
            if (x == 0)
            {
                cout << 1 << "\n";
                break;
            }
            y = (x + y) % p;
            if (y == 0)
            {
                cout << 2 << "\n";
                break;
            }
            if (x == k1 && y == k2)
            {
                cout << "error\n";
                break;
            }
        }
    }
    return 0;
}