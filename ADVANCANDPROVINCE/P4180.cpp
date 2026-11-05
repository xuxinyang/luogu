#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 100005;
constexpr int M = 300005;
constexpr int LOG = 20;
constexpr ll INF = (1LL << 62);
constexpr ll NEG = -(1LL << 62);
// 最小生成树的邻接表
struct Edge
{
    int nxt, to, val;
} e[N << 1];

int h[N], cnt;

void add(int u, int v, int w)
{
    e[++cnt] = {h[u], v, w};
    h[u] = cnt;
}

// 原图的边
struct Edge1
{
    int u, v, w;
    bool used;
} e1[M];

int n, m;
int fa[N], sz[N];
ll ans0;

// 倍增数组
int f[N][LOG], dep[N];
ll mx[N][LOG], mx2[N][LOG];

// BFS 队列
int q[N];

bool cmp(const Edge1 &a, const Edge1 &b)
{
    return a.w < b.w;
}

// 非递归路径压缩
int find(int x)
{
    while (x != fa[x])
    {
        fa[x] = fa[fa[x]];
        x = fa[x];
    }
    return x;
}

// 将数值 x 加入最大值、严格次大值的统计
void upd(ll &a, ll &b, ll x)
{
    if (x == NEG) return;
    if (x > a)
    {
        b = a;
        a = x;
    }
    else if (x < a && x > b)
    {
        b = x;
    }
}

// 建立最小生成树
bool kruskal()
{
    sort(e1 + 1, e1 + m + 1, cmp);
    int num = 0;
    for (int i = 1; i <= m; i++)
    {
        int u = find(e1[i].u);
        int v = find(e1[i].v);
        if (u == v) continue;
        // 按大小合并
        if (sz[u] < sz[v]) swap(u, v);
        fa[v] = u;
        sz[u] += sz[v];
        ans0 += e1[i].w;
        e1[i].used = true;
        num++;
        add(e1[i].u, e1[i].v, e1[i].w);
        add(e1[i].v, e1[i].u, e1[i].w);
        if (num == n - 1) break;
    }
    return num == n - 1;
}

// BFS 处理深度、祖先、最大值和严格次大值
void bfs()
{
    for (int u = 0; u <= n; u++)
    {
        for (int j = 0; j < LOG; j++)
        {
            mx[u][j] = NEG;
            mx2[u][j] = NEG;
        }
    }
    int l = 1, r = 0;
    q[++r] = 1;
    dep[1] = 1;
    while (l <= r)
    {
        int u = q[l++];
        for (int i = h[u]; i; i = e[i].nxt)
        {
            int v = e[i].to;
            int w = e[i].val;
            if (dep[v]) continue;
            dep[v] = dep[u] + 1;
            f[v][0] = u;
            // 一条边只有最大值，没有严格次大值
            mx[v][0] = w;
            mx2[v][0] = NEG;
            for (int j = 1; j < LOG; j++)
            {
                int p = f[v][j - 1];
                f[v][j] = f[p][j - 1];
                ll a = NEG, b = NEG;
                // 合并两段路径的最大值和严格次大值
                upd(a, b, mx[v][j - 1]);
                upd(a, b, mx2[v][j - 1]);
                upd(a, b, mx[p][j - 1]);
                upd(a, b, mx2[p][j - 1]);
                mx[v][j] = a;
                mx2[v][j] = b;
            }
            q[++r] = v;
        }
    }
}

int lca(int u, int v)
{
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (dep[u] - dep[v] >= (1 << i))
        {
            u = f[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (f[u][i] != f[v][i])
        {
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}
// 统计 u 到祖先 p 的路径信息
void query(int u, int p, ll &a, ll &b)
{
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (dep[u] - dep[p] >= (1 << i))
        {
            upd(a, b, mx[u][i]);
            upd(a, b, mx2[u][i]);
            u = f[u][i];
        }
    }
}

// 加入非树边 (u, v, w)，计算可得到的严格次小候选值
ll cal(int u, int v, int w)
{
    int p = lca(u, v);
    ll a = NEG; // 路径最大边权
    ll b = NEG; // 路径严格次大边权
    query(u, p, a, b);
    query(v, p, a, b);
    // 新边比路径最大边大，删除最大边即可
    if (a != NEG && w > a)
    {
        return ans0 - a + w;
    }
    // 新边等于路径最大边，必须删除严格次大边
    if (w == a && b != NEG)
    {
        return ans0 - b + w;
    }
    // 无法通过这条边得到严格更大的生成树
    return INF;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int num = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        // 自环不能加入生成树，直接跳过
        if (u == v)
            continue;

        e1[++num] = {u, v, w, false};
    }
    m = num;
    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        sz[i] = 1;
    }
    // 图不连通时，不存在生成树
    if (!kruskal())
    {
        cout << -1 << '\n';
        return 0;
    }
    bfs();
    ll ans = INF;
    for (int i = 1; i <= m; i++)
    {
        if (!e1[i].used)
        {
            ans = min(ans, cal(e1[i].u, e1[i].v, e1[i].w));
        }
    }
    // 防御性处理：不存在严格次小生成树
    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}