#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int T = 1e5+1, F = -1e5-1, U = 0;
int c, t, n, m, a, b, fa[maxn], ans;
char ch[maxn];
bool book[maxn<<2];
int find(int x)
{
    int res;
    if (x == T || x == F) res = x;
    else if (book[n-x]||x==U) res = U;
    else if (book[x+n]) res = T;
    else if (x < 0)
    {
        if (x == -fa[-x]) res = x;
        else {
            book[x+n] = 1;
            res = find(-fa[-x]);
            book[x+n] = 0;
        }
    }
    else
    {
        if (x == fa[x]) res = x;
        else {
            book[x+n] = 1;
            res = fa[x] = find(fa[x]);
            book[x+n] = 0;
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) fa[i] = i;
        for (int i = 1; i <= m; i++)
        {
            cin >> ch[i];
            if (ch[i] == 'T')
            {
                cin >> a;
                fa[a] = T;
            }
            else if (ch[i] == 'F')
            {
                cin >> a;
                fa[a] = F;
            }
            else if (ch[i] == 'U')
            {
                cin >> a;
                fa[a] = U;
            }
            else
            {
                cin >> a >> b;
                if (ch[i] == '+') fa[a] = fa[b];
                else fa[a] = -fa[b];
            }
        }
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (find(i) == U) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}