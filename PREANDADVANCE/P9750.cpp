#include <bits/stdc++.h>
using namespace std;
int T, M;
double a, b, c, delta;
int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a%b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T >> M;
    while (T--)
    {
        cin >> a >> b >> c;
        delta = sqrt(b*b-4*a*c);
        if (delta < 0) cout << "NO\n";
        else
        {
            
        }
    }
    return 0;
}