#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
ll n, a[N], b[N],f[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = n; i >= 1; i--)
        f[i] = max(f[i+1], a[i]+f[i+max(1ll, b[i])]);
    cout << f[1];
    return 0;
}