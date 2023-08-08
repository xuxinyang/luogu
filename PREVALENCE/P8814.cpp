#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll k, n, d, e, p, q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k;
    while (k--)
    {
        cin >> n >> d >> e;
        ll a = sqrt((n-e*d+2) * (n-e*d+2)-(n*4));
        ll b = n - e*d + 2;
        p = (a + b) / 2;
        q = b - p;
        if (p*q == n && e *d==(p-1)*(q-1)+1 && p&&q)
        {
            cout << min(p, q) << " " << max(p, q) << "\n";
        }
        else cout << "NO\n";

    }
    return 0;
}