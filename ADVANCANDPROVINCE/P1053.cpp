#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4+5;
int n, a[maxn], b[maxn], c[maxn], s[maxn], ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    // 正向
    c[1] = 1; c[2] = a[1];
    for (int i = 1; i <= n; i++)
    {
        if (b[a[i]] != i && a[a[i]] != i || a[b[i]] != i && b[b[i]] != i)
        {
            cout << "-1";
            return 0;
        }
        if (a[c[i]] == c[i-1]) c[i+1] = b[c[i]];
        else c[i+1] = a[c[i]];
    }
    ans = n;
    for (int i = 1; i <= n; i++)
    {
        s[(i-c[i]+n)%n]++;
        ans = min(ans, n-s[(i-c[i]+n)%n]);
    }
    // 反向
    memset(s, 0, sizeof(s));
    memset(c, 0, sizeof(c));
    c[0] = 1; c[1] = b[1];
    for (int i = 1; i <= n; i++)
    {
        if (b[c[i]] == c[i-1]) c[i+1] = a[c[i]];
        else c[i+1] = b[c[i]];
    }
    for (int i = 1; i <= n; i++)
    {
        s[(i-c[i]+n)%n]++;
        ans = min(ans, n-s[(i-c[i]+n)%n]);
    }
    cout << ans;
    return 0;
}