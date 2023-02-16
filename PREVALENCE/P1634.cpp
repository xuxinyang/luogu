#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main()
{
    ll x, n, ans;
    cin >> x >> n;
    ans = 1;
    // 1 11 110+11=121
    for (int i = 1; i <= n; i++)
    {
        ans = ans*x+ans;
    }
    cout << ans << endl;
    return 0;
}