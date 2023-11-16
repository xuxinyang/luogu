#include <bits/stdc++.h>
using namespace std;
int ans = 0;
double v, v0;
int main()
{
    cin >> v >> v0;
    if (v0 >= v)
    {
        cout << 0;
        return 0;
    }
    double k = v / v0;
    if (int(k) == k && int(k) % 2 != 0)
    {
        cout << 0;
        return 0;
    }
    if (v0 == 1)
    {
        cout << v / (2 * v0);
        return 0;
    }
    cout << int(v / (2 * v0) + 0.5);
    return 0;
}