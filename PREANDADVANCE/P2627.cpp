#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+5;
ll n, k, a[maxn], f[maxn][2], s[maxn], q[maxn];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i-1]+a[i];
    int head = 1, tail = 1;
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        while (head <= tail && i-q[head] > k) head++;
        f[i][1] = s[i]+f[q[head]][0]-s[q[head]];
        while (head <= tail && f[i][0]-s[i]>f[q[tail]][0]-s[q[tail]]) tail--;
        q[++tail] = i;
    }
    printf("%lld\n", max(f[n][0], f[n][1]));
    return 0;
}