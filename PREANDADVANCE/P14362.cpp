#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N = 1e4+20;
constexpr int M = 1e6+5;
constexpr int K = 12;
struct Edge {
    int u, v, w;
};
int n, m, k;
int fa[N], siz[N], cnt[K];
ll c[K], ans;
Edge road[M], a[K][N], tree[K][N];
bool cmp(const Edge &x , const Edge &y)
{
    return x.w < y.w;
}
void init()
{
    for (int i = 1; i <= n + k; i++) fa[i] = i, siz[i] = 1;
}
int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
bool merge(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) swap(x, y);
    fa[y] = x;
    siz[x] += siz[y];
    return true;
}
ll get_tree(int d, int j)
{
    init();
    int p = 1, q = 1;
    cnt[d+1] = 0; 
    ll sum = 0;
    int need = n + d;
    while (cnt[d+1] < need && (p <= cnt[d] || q <= n)) 
    {
        Edge e;
        if (q > n) e = tree[d][p++];
        else if (p > cnt[d]) e = a[j][q++];
        else if (tree[d][p].w <= a[j][q].w) e = tree[d][p++];
        else e = a[j][q++];
        if (merge(e.u, e.v))
        {
            cnt[d+1]++;
            tree[d+1][cnt[d+1]] = e;
            sum += e.w;
        }
    }
    return sum;
}
/**
 * @brief 枚举所有情况
 * 
 * @param d 已经选择的乡镇数量
 * @param last 上一个已经选择的乡镇编号
 * @param sum 当前 MST 的费用
 * @param cost 当前乡镇改造费用之和
 */
void dfs(int d, int last, ll sum, ll cost)
{
    ans = min(ans, sum + cost);
    for (int j = last + 1; j <= k; j++)
    {
        ll new_sum = get_tree(d, j);
        dfs(d+1, j, new_sum, cost+c[j]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> road[i].u >> road[i].v >> road[i].w;
    }
    for (int j = 1; j <= k; j++) 
    {
        cin >> c[j];
        for (int i = 1; i <= n; i++)
        {
            a[j][i].u = n + j;
            a[j][i].v = i;
            cin >> a[j][i].w;
        }
        sort(a[j]+1, a[j]+n+1, cmp);
    }
    // 求原有道路的最小生成树
    sort(road+1, road+m+1, cmp);
    init();
    ll sum = 0;
    for (int i = 1; i <= m && cnt[0] < n-1; i++)
    {
        if (merge(road[i].u, road[i].v))
        {
            cnt[0]++;
            tree[0][cnt[0]] = road[i];
            sum += road[i].w;
        }
    }
    ans = sum;
    dfs(0, 0, sum, 0);
    cout << ans;
    return 0;
}