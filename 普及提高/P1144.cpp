#include <bits/stdc++.h>
using namespace std;
const int mod = 1e5+3;
const int maxn = 1e6+5;
const int maxm = 4e6+5;
int n, m, x, y, tot;
int head[maxn], to[maxm], nxt[maxm], d[maxn], ans[maxn];
bool flag[maxn];
priority_queue<pair<int, int> > q;
void add(int x, int y)
{
    to[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        add(x, y), add(y, x);
    }   
    for (int i = 1; i <= n; i++)
    {
        d[i] = 1e9, flag[i] = 0;
    }
    d[1] = 0, ans[1] = 1;
    q.push(make_pair(0, 1));
    while(!q.empty())
    {
        x = q.top().second, q.pop();
        if (flag[x]) continue;
        flag[x] = 1;
        for (int i = head[x]; i; i = nxt[i])
        {
            y = to[i];
            if (d[y] > d[x] + 1)
            {
                d[y] = d[x] + 1;
                ans[y] = ans[x];
                q.push(make_pair(-d[y], y));
            }
            else if (d[y] == d[x] + 1)
            {
                ans[y] += ans[x];
                ans[y] %= mod;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
    return 0;
}