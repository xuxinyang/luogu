#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, k;
ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a%b);
} 
ll lcm(ll a, ll b)
{
    return a*b / gcd(a, b);
}
bool check(ll x)
{
    return x/n + x/m - 2*(x/lcm(n, m)) >= k;
}
int main()
{
    
    cin >> n >> m >> k;
    ll l = 1, r = 1e18;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r;
    return 0;
}