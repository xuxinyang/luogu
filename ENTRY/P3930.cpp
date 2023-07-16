#include <bits/stdc++.h>
using namespace std;
long long x, y, z, ans = LLONG_MAX;
int main()
{
    cin >> y >> z;
    for (long long i = 100000; i <= 999999; i++)
    {
        x = i * 1000000 + y;
        ans = min(ans, abs(x-z));
    }
    cout << ans;
    return 0;
}