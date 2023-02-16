#include <bits/stdc++.h>
using namespace std;
const int mod = 80112002;
const int maxn = 1e6+5;
queue<int> q;
int d[maxn], in[maxn], eat[maxn], head[maxn];
int n, m, tot, ans;
struct Edge{
    int to, nxt;
} edges[maxn];
// 链式前向星存图
void add(int u, int v)
{
    edges[++tot].to = v;
    edges[tot].nxt = head[u];
    head[u] = tot;
}
// 拓扑排序
void topo()
{
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0) // 入度为0的点入队
        {
            q.push(i);
            d[i]++;
        }
    }
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int i = head[p]; i; i = edges[i].nxt)
        {
            int go = edges[i].to;
            d[go] = (d[go] + d[p]) % mod;
            in[go]--;
            if (in[go] == 0) q.push(go);    // 当吃go的都入队后，再将go入队
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        in[b]++;    // 吃b的加1
        eat[a]++;   // a吃的加1
    }
    topo();
    for (int i = 1; i <= n; i++)
    {
        if (eat[i] == 0) ans = (ans + d[i]) % mod;
    }
    cout << ans << endl;
    return 0;
}