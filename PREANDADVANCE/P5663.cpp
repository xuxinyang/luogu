#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, m, q;
int odd[maxn], even[maxn];
struct Edge
{
    int to, next;
} edges[maxn<<1];
int head[maxn], tot;
void add(int u, int v)
{
    edges[++tot] = {v, head[u]};
    head[u] = tot;
}
void bfs()
{
    memset(odd, 0x3f, sizeof(odd));
    memset(even, 0x3f, sizeof(even));
    queue<pair<int, int> > q;
    for (int i = head[1]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        odd[v] = 1;
        q.push(make_pair(v, 1));
    }
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = head[x]; i; i = edges[i].next)
        {
            int v = edges[i].to;
            if (y % 2 == 1)
            {
                if (y+1 < even[v])
                {
                    even[v] = y+1;
                    q.push(make_pair(v, y+1));
                }
            }
            else
            {
                if (y+1 < odd[v])
                {
                    odd[v] = y+1;
                    q.push(make_pair(v, y+1));
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    bfs();
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (y % 2 == 0)
        {
            if (even[x] > y) cout << "No\n";
            else cout << "Yes\n";
        }
        else
        {
            if (odd[x] > y) cout << "No\n";
            else cout << "Yes\n";
        }
    }
    return 0;
}