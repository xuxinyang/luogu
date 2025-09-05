#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
ll n, k, l, c[N], ans;
bool check(int x)
{
    ll s = 0;
    for (int i = 1; i <= n; i++)
    {
        if (c[i] < x)
        {
            // 引用次数超过k了，直接返回0
            if (x - c[i] > k) return 0;
            s += x - c[i];  // 计算需要引用的次数
        }
        if (s > k*l) return 0;  // 如果引用次数超过了限制，返回0
        if (i >= x) return 1;   // 超过 x 篇了，可以了
    }
    return 1;
}
int main()
{
    cin >> n >> k >> l;
    for (int i = 1; i <= n; i++) cin >> c[i];
    sort(c + 1, c + n + 1, greater<int>());
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}