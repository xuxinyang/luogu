#include <bits/stdc++.h>
using namespace std;
int n;
int gcd(int x, int y)
{
    return __gcd(x, y);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int a0, a1, b0, b1;
    while (n--)
    {
        cin >> a0 >> a1 >> b0 >> b1;
        int p = a0 / a1, q = b1 / b0, ans = 0;
        for (int i = 1; i * i <= b1; i++)
        {
            if (b1 % i == 0)
            {
                if (i % a1 == 0 && gcd(i/a1, p) == 1 && gcd(q, b1/i) == 1) ans++;
                int m = b1 / i;
                if (i == m) continue;
                if (m % a1 == 0 && gcd(m/a1, p) == 1 && gcd(q, b1/m) == 1) ans++;
            }  
        }
        cout << ans << "\n";
    }
    return 0;
}