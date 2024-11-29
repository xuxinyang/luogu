#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int a[maxn], n, m, q, u, v, t;
queue<int> qw[4];
int main()
{
    cin >> n >> m >> q >> u >> v >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= n; i++)
        qw[1].push(a[i]);
    for (int i = 0; i < m; i++)
    {
        pair<int, int> p = max({make_pair(qw[1].empty() ? -inf : qw[1].front(), 1),
                                make_pair(qw[2].empty() ? -inf : qw[2].front(), 2),
                                make_pair(qw[3].empty() ? -inf : qw[3].front(), 3)});
        int x = p.first + q * i, j = p.second;
        qw[j].pop();
        int b = 1ll * x * u / v, c = x - b;
        qw[2].push(b - q - q * i);
        qw[3].push(c - q - q * i);
        if (i % t == t - 1) cout << x << " ";
    }
    cout << "\n";
    for (int i = 1; i <= n + m; i++)
    {
        pair<int, int> p = max({make_pair(qw[1].empty() ? -inf : qw[1].front(), 1),
                                make_pair(qw[2].empty() ? -inf : qw[2].front(), 2),
                                make_pair(qw[3].empty() ? -inf : qw[3].front(), 3)});
        int x = p.first, j = p.second;
        qw[j].pop();
        if (i % t == 0) cout << x+q*m << " ";
    }
    return 0;
}