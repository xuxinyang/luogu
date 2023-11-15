#include <bits/stdc++.h>
using namespace std;

int main()
{
    long double sum = 0, x = 0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> x)
    {
        sum += x*1e6;
    }
    cout << fixed << setprecision(5) << sum/1e6;
    return 0;
}