#include <bits/stdc++.h>
using namespace std;
// 树状数组维护
constexpr int N = 5e5+5;
int m, a[N], b[N], c[N];
int lowbit(int x) { return x & -x; }
void add(int x, int y)
{
    for (int i = x; i <= m; i += lowbit(i)) c[i] += y;
}
int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += c[i];
    return res;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b+1, b+n+1);
    m = unique(b+1, b+n+1) - b - 1; // 离散化
    long long ans = 0;
    for (int i = n; i; i--)
    {
        int k = lower_bound(b+1, b+m+1, a[i]) - b;
        ans += sum(k-1);
        add(k, 1);
    }
    cout << ans;
    return 0;
}