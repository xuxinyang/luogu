#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = INT_MAX;
int n, s, last;
ll ans, c, y, minc;
int main()
{
    cin >> n >> s;
    minc = inf;
    last = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> c >> y;
        if (c < minc + s * (i - last)) ans += c * y, minc = c, last = i;
        else ans += (minc + s * (i - last)) * y;
    }
    cout << ans;
    return 0;
}