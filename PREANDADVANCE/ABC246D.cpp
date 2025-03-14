#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf LLONG_MAX
ll l, r, n, x;
bool check(ll x, ll y)
{
    return (x*x+y*y)*(x+y) >= n;
}
int main()
{
    cin >> n;
    l = 0, r = 1e6, x=inf;
    while (l <= r)
    {
        if (check(l, r)) x = min((l*l+r*r)*(l+r),x), r--;
        else l++;
    }
    cout << x;
    return 0;
}