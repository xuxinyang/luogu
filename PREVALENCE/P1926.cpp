#include <bits/stdc++.h>
using namespace std;
int n, m, k, r, p[15], w[15], v[15], t[155], ans;
int main()
{
    cin >> n >> m >> k >> r;
    for (int i = 1; i <= n; i++) cin >> p[i];
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= m; i++) cin >> v[i];
    for (int i = 1; i <= m; i++)
    {
        for (int j = r; j >= w[i]; j--)
            t[j] = max(t[j], t[j-w[i]] + v[i]);
    }
    int c = r;
    while (t[c] >= k) c--;
    c++;
    c = r - c;  // 剩余时间
    for (int i = 1; i <= n; i++)
    {
        if (c > p[i]) ans++, c-=p[i];
        else break;
    }
    cout << ans;
    return 0;
}