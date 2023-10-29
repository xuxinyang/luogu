#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
const int maxn = 1e5 + 5;
ll n, d, idx, v[maxn], a[maxn], s[maxn], ans;
ll minPrice, sum;
int main()
{
    cin >> n >> d;
    for (int i = 2; i <= n; i++)
    {
        cin >> v[i];
        s[i] = s[i - 1] + v[i];   // 统计到站点i的距离
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    minPrice = a[1];
    for (int i = 1; i <= n - 1;)
    {
        int idx = i;
        if (a[i] >= minPrice)
        {
            while (a[i] >= minPrice && i <= n - 1) i++;
            ans += minPrice * (ll)(ceil(1.0 * (s[i] - sum) / d));
            sum += (ll)ceil(1.0 * (s[i] - sum) / d) * d;
        }
        else
        {
            ans += minPrice * (ll)(ceil(1.0 * (s[i + 1] - sum) / d));
            sum += (ll)ceil(1.0 * (s[i + 1] - sum) / d) * d;
            i++;
        }
        minPrice = a[i];
    }
    cout << ans;
    return 0;
}