#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll x, ll y)
{
    if (y == 0) return x;
    else return gcd(y, x%y);
}
void calc(ll x1, ll y1, ll x2, ll y2, char c, ll &numerator, ll &denominator)
{
    if (c == '+') numerator = x1 * y2 + x2 * y1, denominator = y1 * y2;
    else numerator = x1 * y2 - x2 * y1, denominator = y1 * y2;
    ll gcdv = gcd(abs(numerator), abs(denominator));
    numerator = numerator / gcdv;
    denominator = denominator / gcdv;
}
int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    ll a1, b1, a2, b2;
    char c;
    scanf("%lld/%lld", &a1, &b1);
    while (scanf("%c%lld/%lld", &c, &a2, &b2) != EOF)
    {
        calc(a1, b1, a2, b2, c, a1, b1);
        // cout << a1 << " " << b1 << " " << c << " " << a2 << " " << b2 << endl;
    }
    if (a1 % b1 == 0) printf("%lld\n", a1 / b1);
    else printf("%lld/%lld\n", a1, b1);
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}