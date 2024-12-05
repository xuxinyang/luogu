#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int maxn = 1e6+5;
ull n, m, c, k, p, q, x, need, give, pos;
bool flag[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> c >> k;
    for (int i = 1; i <= n; i++) {cin >> x; need |= x;}
    for (int i = 1; i <= m; i++) {cin >> p >> q; give |= (1ull<<p);}
    for (int i = 0; i < k; i++)
        pos += !((give>>i)&1) || ((need>>i)&1);
    if (pos == 64 && !n) cout << "18446744073709551616";
    else 
    {
        if (pos == 64) cout << -n;
        else cout << (1ull<<pos)-n;
    }
    return 0;
}