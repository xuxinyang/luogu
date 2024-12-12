#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+5;
const int maxl = 1e6+5;
const ll inf = 1e18;
ll t, n, m, L, V, p[maxn];
struct Car
{
    ll d, v, a;
};
Car cars[maxn];
struct Node
{
    ll l, r;
};
Node nodes[maxn];   // 记录可以检测的左右区间
ll speed(ll idx, ll pos)
{
    if (cars[idx].d > pos) return -inf;
    return cars[idx].v*cars[idx].v+2*cars[idx].a*(pos-cars[idx].d);// 2as+v0^2
}
void solve()
{
    cin >> n >> m >> L >> V;
    ll t1 = 0, t2 = 0, maxr=0; // 记录数目
    for (int i = 1; i <= n; i++)
        cin >> cars[i].d >> cars[i].v >> cars[i].a;
    for (int i = 1; i <= m; i++) cin >> p[i];
    for (int i = 1; i <= n; i++)
    {
        if (cars[i].a >= 0) // 加速/匀速，找可以检测到超速的最左边一个检测器
        {
            int l = 1, r = m+1;
            while (l < r)
            {
                int mid = (l+r) >> 1;
                if (speed(i, p[mid]) > V*V) r = mid;
                else l = mid+1;
            }
            if (l != m+1)   // 可以检测到
                nodes[++t1] = {l, m};
        }
        else    // 减速运动，找到最右侧科技检测到超速的检测器
        {
            int l = 0, r = m;
            while (l < r)
            {
                int mid = (l+r+1)>>1;
                // 经过mid的速度比较大，尝试在右区间查找
                if (2ll*p[mid]*cars[i].a>=2ll*cars[i].a*cars[i].d-cars[i].v*cars[i].v) l = mid; 
                else r = mid-1;
            }
            if (!l) continue;   // 速度太小，l点没超速，后续也不会超速
            int r1 = l;
            l = 1, r = m+1;
            while (l < r)
            {
                int mid = (l+r) >> 1;
                if (p[mid] < cars[i].d) l = mid+1;
                else r = mid;
            }
            if (l == m + 1) continue; // 最后端点也超速，一直都超速
            int l1 = l - 1;
            while (l1 < r1)
            {
                int mid = (l1 + r1 + 1) >> 1;
                if (speed(i, p[mid]) > V*V) l1 = mid;
                else r1 = mid-1;
            }
            if (l1 == l-1) continue;
            nodes[++t1] = {l, l1};
        }
    }
    cout << t1 << " ";
    sort(nodes+1, nodes+t1+1, [](Node A, Node B){
        return A.r < B.r;
    });
    for (int i = 1; i <= t1; i++)
    {
        // cout << nodes[i].l << " " << nodes[i].r << "\n";
        if (maxr >= nodes[i].l) continue;
        t2++, maxr = nodes[i].r;
    }
    cout << m-t2 << "\n";
}
int main()
{
    cin >> t;
    while (t--) solve();
    return 0;
}