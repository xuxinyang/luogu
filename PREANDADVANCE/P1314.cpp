#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2e5+5;
int n, m, l, r, w[maxn], v[maxn], le[maxn], ri[maxn];
ll s, sum, ans, sumc[maxn], sumv[maxn], res = LLONG_MAX;
bool check(int x)
{
    sum = 0;
    memset(sumc, 0, sizeof(sumc));
    memset(sumv, 0, sizeof(sumv));
    for (int i = 1; i <= n; i++)
    {
        if (w[i] >= x) sumc[i] = sumc[i-1] + 1, sumv[i] = sumv[i-1] + v[i];
        else sumc[i] = sumc[i-1], sumv[i] = sumv[i-1];  
    }
    for (int i = 1; i <= m; i++)
    {
        sum += (sumc[ri[i]] - sumc[le[i]-1]) * (sumv[ri[i]] - sumv[le[i]-1]);
    }
    res = min(res, abs(sum - s));
    return sum >= s;
}
int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
        r = max(r, w[i]);
    }
    for (int i = 1; i <= m; i++)
        cin >> le[i] >> ri[i];
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << res << endl;
    return 0;
}