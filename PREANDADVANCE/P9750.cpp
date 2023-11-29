#include <bits/stdc++.h>
using namespace std;
int T, M, a, b, c;
int delta;
int storage[1005];
int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a%b);
}
void getIn(int x, int &p, int &q)
{
    for (int i = 2; i <= 1000; i++)
    {
        while (x % i == 0 && x > 0) storage[i]++, x /= i;
        for (int j = 1; j <= storage[i]/2; j++)
        {
            p *= i;
        }
        if (storage[i] % 2 == 1) q *= i;
    }
}
// (-b + sqrt(b^2-4ac))/(2a)
int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T >> M;
    while (T--)
    {
        cin >> a >> b >> c;
        delta = b*b-4*a*c;
        if (delta < 0) cout << "NO\n";
        else
        {
            // 可以整合到一起
            if (int(sqrt(delta))*int(sqrt(delta)) == delta)
            {
                int p1 = -b + sqrt(delta) ;
                int p2 = -b - sqrt(delta);
                if (a < 0)
                {
                    if (p2 * a < 0) cout << "-";
                    if (abs(p2) % abs(2*a) == 0) cout << abs(p2)/abs(2*a) << "\n";
                    else cout << abs(p2)/abs(gcd(abs(p2), abs(2*a))) << "/" << 2*abs(a)/gcd(abs(p2), abs(2*a)) << "\n";
                }
                else
                {
                    if (p1 * a < 0) cout << "-";
                    if (abs(p1) % abs(2*a) == 0) cout << abs(p1)/abs(2*a) << "\n";
                    else cout << abs(p1)/abs(gcd(abs(p1), abs(2*a))) << "/" << 2*abs(a)/gcd(abs(p1), abs(2*a)) << "\n";    
                }
                
            }
            else
            {
                // 不能整合，先输出第一部分
                if (-b*a < 0) cout << "-";
                if (abs(b%(2*a)) == 0 && abs(b) != 0) cout << abs(b/2/a);
                else if (abs(b) == abs(2 * a)) cout << 1;
                else if (b != 0)
                {
                    cout << (abs(-b) / gcd(abs(2*a), abs(-b))) << '/' << abs(2*a) / gcd(abs(2*a), abs(-b));
                }
                // 再输出第二部分
                if (b != 0) cout << "+";
                int w = delta, p = 1, q = 1;
                memset(storage, 0, sizeof(storage));
                getIn(w, p, q);
                if (p/gcd(p, abs(2*a))!=1) cout << p/gcd(p, abs(2*a)) << "*";
                cout << "sqrt(" << q << ")";
                // cout << abs(2*a)/gcd(p, abs(2*a));
                if (int(abs(2*a)/gcd(p, abs(2*a)) != 1)) cout << "/" << abs(2*a)/gcd(p, abs(2*a));
                cout << "\n";
            }
        }
    }
    return 0;
}