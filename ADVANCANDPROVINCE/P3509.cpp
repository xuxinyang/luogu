#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6+5;
ll n, k, m, a[maxn], nxt[maxn], ans[maxn];
ll tmp[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int head = 1, tail = k + 1;
    nxt[1] = k + 1;
    for (int i = 2; i <= n; i++)
    {
        while (tail + 1 <= n && a[i]-a[head] > a[tail+1]-a[i])
        {
            head++, tail++;
        }
        if (a[i] - a[head] >= a[tail] - a[i]) nxt[i] = head;
        else nxt[i] = tail;
    }
    for (int i = 1; i <= n; i++) ans[i] = i;
    while (m)
    {
        if (m & 1)
            for (int i = 1; i <= n; i++)
                ans[i] = nxt[ans[i]];
        memcpy(tmp, nxt, sizeof(tmp));
        for (int i = 1; i <= n; i++)
            nxt[i] = tmp[tmp[i]];
        m >>= 1;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}