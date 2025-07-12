#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n, a[N], q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int gcd = 0;
    for (int i = 2; i <= n; i++)
    {
        gcd = __gcd(gcd, abs(a[i]-a[1]));
    }
    for (int i = 1; i <= q; i++)
    {
        cout << __gcd(gcd, a[1]+i) << "\n";
    }
    return 0;
}