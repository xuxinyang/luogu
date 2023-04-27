#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
long long n, a[maxn], m, p, s, k, sum, ans;
int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    scanf("%lld %lld %lld %lld", &m, &p, &s, &k);
    for (int i = 1; i <= n; i++)
        sum += a[i] * (m - i);
    sum += s * (m - p);
    ans = m + int(sum * 1.0 / k + 0.5 * (sum > 0 ? 1 : -1)); 
    if (ans > n) ans = n;
    if (ans < 1) ans = 1;
    printf("%lld", ans);
    return 0;
}