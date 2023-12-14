#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct Edge
{
    int to, next, w;
};
Edge edges[maxn << 1];
int tot, head[maxn];
int n, vis[maxn], fa[maxn], w[maxn];
// 分表表示点在环上，存在环上的点，点权值
int inc[maxn], cv[maxn], cw[maxn], cn;
double d[maxn]; // d[i]表示以i为根节点的子树深度
/**
 * A[i] = max{前缀中 链的长度 + 节点树的深度}
 * B[i] = max{前缀中 两棵树的深度 + 这两个节点的距离}
 * C[i] = max{后缀中 链的长度 + 节点树的深度}
 * D[i] = max{后缀中 两棵树的深度 + 这两个节点的距离}
 */
double A[maxn], B[maxn], C[maxn], D[maxn];
double ans1, ans2 = 1e18;
void add(int u, int v, int w)
{
    edges[++tot] = Edge{v, head[u], w};
    head[u] = tot;
}
bool find(int u)
{
    vis[u] = true;
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to;
        if (v != fa[u])
        {
            fa[v] = u, w[v] = edges[i].w;
            if (!vis[v]) // v还没访问
            {
                if (find(v)) return 1;
            }
            else
            {
                int p = u;
                while (1)
                {
                    inc[p] = 1, cv[++cn] = p;
                    cw[cn] = w[p], p = fa[p];
                    if (p == u) break;
                }
                return 1;
            }
        }
    }
    return 0;
}
void dfs(int u, int f)
{
    for (int i = head[u]; i; i = edges[i].next)
    {
        int v = edges[i].to, w = edges[i].w;
        if (!inc[v] && v != f)
        {
            dfs(v, u);
            ans1 = max(ans1, d[u] + d[v] + w);
            d[u] = max(d[u], d[v] + w);
        }
    }
}
int main()
{
    int x, y, z;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    find(1); // 先深搜找环
    for (int i = 1; i <= cn; ++i)
        dfs(cv[i], 0); // 深搜求直径ans1
    double sum = 0, mx = 0;
    for (int i = 1; i <= cn; ++i)
    {
        sum += cw[i - 1];
        A[i] = max(A[i - 1], sum + d[cv[i]]);
        B[i] = max(B[i - 1], mx + d[cv[i]] + sum);
        mx = max(mx, d[cv[i]] - sum);
    }
    sum = mx = 0;
    double cn1 = cw[cn];
    cw[cn] = 0;
    for (int i = cn; i >= 1; --i)
    {
        sum += cw[i];
        C[i] = max(C[i + 1], sum + d[cv[i]]);
        D[i] = max(D[i + 1], mx + d[cv[i]] + sum);
        mx = max(mx, d[cv[i]] - sum);
    }
    double res;
    for (int i = 1; i < cn; ++i)
    {
        res = max(max(B[i], D[i+1]), A[i] + C[i+1] + cn1);
        ans2 = min(ans2, res);
    }
    ans2 = min(ans2, B[cn]);  // 断最后一条边
    cout << fixed << setprecision(1) << max(ans1, ans2)/2;
    return 0;
}