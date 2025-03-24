#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5+5;
ll n, a[maxn], b[maxn], d[maxn], ans;
int main()
{
    cin >> n;
    for (int i = 1; i <=n<<1; i++) cin >> a[i];
    for (int i = 1; i <=n<<1; i++) cin >> b[i];
    for (int i = 1; i <=n<<1; i++)
    {
        ans += a[i];
        d[i] = b[i]-a[i];
    }
    sort(d+1, d+1+(n<<1));
    for (int i = n+1; i <= n<<1; i++) ans += d[i];
    cout << ans;
    return 0;
}