#include <bits/stdc++.h>
using namespace std;
constexpr int N = 65;
int n, sum, mn = N, mx, d;
int len[N], a[N], pre[N];
/**
 * @brief 搜索
 * u: 当前长棍还有 u 没有拼
 * k: 还有 k 根长棍没有拼
 * p: 当前长棍得最短短棍长度是 p
 */
void dfs(int u, int k, int p)
{
    if (u == 0) {dfs(d, k-1, a[n]); return ;}
    if (k == 0) {cout << d << "\n"; exit(0);}
    p = (p < u) ? p : u;
    while (p && len[p] == 0) --p;
    while (p)
    {
        if (len[p])
        {
            --len[p];
            dfs(u-p, k, p);
            ++len[p];
            if ((u == p) || (u == d)) return ;
            p = pre[p];
        }
        else p = pre[p];
    }
}
int main()
{
    cin >> n;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        sum += x;
        ++len[a[i] = x];
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != a[i-1]) pre[a[i]] = a[i-1];
    }
    for (d = a[n]; (d << 1) <= sum; ++d)
    {
        if (sum%d == 0) dfs(d, sum/d, a[n]);
    }
    cout << sum;
    return 0;
}