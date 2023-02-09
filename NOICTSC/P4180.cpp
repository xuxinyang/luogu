#include <bits/stdc++.h>
using namespace std;
#define re register
#define il inline
#define int long long // 把所有int转成longlong
#define debug printf("Now is line %d\n", __LINE__);
il int read()
{
    re int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
    return x * f;
} // 快读
#define maxm 300005
#define inf 12345678900000000
#define maxn 100005
struct Edge
{
    int u, v, w, next;
} e[maxm << 1];
struct qj
{
    int ma, ma2;
} q[maxn << 2];
struct Edge1
{
    int u, v, w;
    bool operator<(const Edge1 &x) const { return w < x.w; } // 按照边权排序
} edge[maxm];
int n, m, vis[maxm], ans = inf, head[maxn], cnt, fa[maxn], mtree;
il void add(int u, int v, int w)
{
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
} // 前向星加边
namespace smallesttree
{
    il int find(int x)
    {
        while (x != fa[x])
            x = fa[x] = fa[fa[x]];
        return x;
    } // 并查集找祖先
    il void init()
    {
        for (re int i = 1; i <= n; i++)
            fa[i] = i; // 预处理并查集
        for (re int i = 0; i < m; i++)
            edge[i].u = read(), edge[i].v = read(), edge[i].w = read();
    }
    il void kruskal()
    {
        init();
        sort(edge, edge + m);
        re int T = 0;
        for (re int i = 0; i < m; ++i)
        {
            re int eu = find(edge[i].u), ev = find(edge[i].v); // 寻找祖先
            if (eu != ev)
            {
                add(edge[i].u, edge[i].v, edge[i].w), add(edge[i].v, edge[i].u, edge[i].w);
                mtree += edge[i].w; // 记录子树大小
                fa[ev] = eu;        // 合并
                vis[i] = 1;         // 标记该边为树边
                if (++T == n - 1)
                    break; // 边数等于节点数+1即为一颗树
            }
        }
    }
}
// 求出最小生成树
namespace treecut
{
    int dep[maxn], father[maxn], top[maxn], W[maxn], a[maxn], size[maxn], son[maxn], seg[maxn], col;
    // dep:深度 father:父亲节点 top:重链的顶端 W:到根节点的距离 a:点的权值 size:子树大小 son:重儿子 seg:在线段树中的序号（dfs序）
    il void dfs1(int u, int fr)
    {
        dep[u] = dep[fr] + 1;
        size[u] = 1;
        father[u] = fr;
        for (re int i = head[u]; i; i = e[i].next)
        {
            re int v = e[i].v;
            if (v != fr)
            {
                W[v] = W[u] + e[i].w; // W为每一个点到根节点的距离
                dfs1(v, u);
                size[u] += size[v];
                if (size[v] > size[son[u]])
                    son[u] = v;
            }
        }
    } // 预处理出dep、size、father以及son
    il void dfs2(int now, int fi)
    {
        top[now] = fi;
        seg[now] = ++col;
        a[col] = W[now] - W[father[now]]; // a为点的权值（它与之父亲节点边的权值）（相当于前缀和）
        if (!son[now])
            return;
        dfs2(son[now], fi);
        for (re int i = head[now]; i; i = e[i].next)
        {
            re int v = e[i].v;
            if (v != son[now] && v != father[now])
                dfs2(v, v);
        }
    } // 预处理出每个节点的top、seg以及权值
// 树剖模板就不解释了
#define ls k << 1
#define rs k << 1 | 1
    il bool CMP(int a, int b)
    {
        return a > b;
    }
    il int getse(int x, int g, int z, int c)
    {
        re int a[5] = {x, g, z, c};
        sort(a, a + 4, CMP);
        for (re int i = 1; i < 3; ++i)
        {
            if (a[i] != a[0])
                return a[i];
        }
    } // 找到两个区间的最大值和严格次大值（四个数）的最大值与严格次大值
    // 就是合并两个区间的最大值和严格次大值
    il void build(int k, int l, int r)
    {
        if (l == r)
        {
            q[k].ma = a[l];
            return;
        }
        re int mid = (l + r) >> 1;
        build(ls, l, mid), build(rs, mid + 1, r);
        q[k].ma = max(q[ls].ma, q[rs].ma);
        q[k].ma2 = getse(q[ls].ma, q[rs].ma, q[ls].ma2, q[rs].ma2);
    } // 预处理出区间最大值与次大值
    il qj query(int k, int l, int r, int ll, int rr)
    {
        if (ll > r || rr < l)
            return (qj){-inf, -inf};
        if (ll <= l && rr >= r)
            return (qj){q[k].ma, q[k].ma2};
        re int mid = (l + r) >> 1;
        re qj t1 = query(ls, l, mid, ll, rr), t2 = query(rs, mid + 1, r, ll, rr);
        return (qj){max(t1.ma, t2.ma), getse(t1.ma, t2.ma, t1.ma2, t2.ma2)};
    } // 查询区间的区间的最大值与次小值
    il int LCA(int u, int v, int d)
    {
        re int need = -inf;
        while (top[u] != top[v])
        {
            if (dep[top[u]] < dep[top[v]])
                swap(u, v);
            qj temp = query(1, 1, n, seg[top[u]], seg[u]);
            u = father[top[u]];
            need = max(need, (temp.ma == d) ? temp.ma2 : temp.ma); // 严格次小边（如果temp.ma==k就是非严格次小）
        }
        if (dep[u] < dep[v])
            swap(u, v); // 找到LCA
        qj temp = query(1, 1, n, seg[v] + 1, seg[u]);
        return max(need, (temp.ma == d) ? temp.ma2 : temp.ma); // 同上
    }
    il void init()
    {
        dfs1(1, 0), dfs2(1, 1), build(1, 1, n);
    }
}
// 树链剖分
signed main()
{
    n = read(), m = read();
    smallesttree::kruskal(); // 求出最小生成树
    treecut::init();         // 预处理
    for (re int i = 0; i < m; ++i)
    {
        if (vis[i])
            continue; // 枚举所有非树边（没有在最小生成树的边）
        re int temp = mtree /*最小生成树边权和*/ + edge[i].w /*本来的树边的边权*/ - treecut::LCA(edge[i].u, edge[i].v, edge[i].w) /*找到严格次小边的边权*/;
        if (ans > temp && temp != mtree + e[i].w /*其实就是严格此小边不为0（没有找到严格次小边）*/ && temp > mtree)
            ans = temp;
    }
    printf("%lld", ans);
    return 0;
}