#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int W, S, P;
struct Point
{
    int s, t;
};
Point a[45];
map<int, int> f;
int ans;
void dfs(int x, int v)
{
    if (v >= f[x])
        return;
    f[x] = v;
    if (x > a[P].s || P == 0)
    { 
        ans = min(ans, v + (W-x+S-1) / S);
        return;
    }
    for (int i = 1; i <= P; i++)
    {
        if (a[i].s < x)
            continue;
        if (a[i].s == x)
        {
            dfs(a[i].t, v);
            return;
        }
        int t = ceil(1.0 * (a[i].s - x) / S);
        dfs(a[i].t, v + t); // 刚好落在虫洞时的最少步数，并且传送到另一端。
        for (int j = a[i].s + 1; j <= a[i].s + S - 1; j++)
        {                       // 跨越虫洞，枚举落脚点。
            if (j <= t * S + x) // 分类讨论，推式子。
                dfs(j, v + (a[i].s - x) / S + 1);
            else
                dfs(j, v + t + 1);
        }
        break;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    while (cin >> W && W)
    {
        cin >> S >> P;
        f.clear();
        for (int i = 1; i <= P; i++)
        {
            cin >> a[i].s >> a[i].t;
            f[a[i].s] = f[a[i].t] = inf;
            for (int j = 1; j <= S - 1; j++) f[a[i].s + j] = inf;
        }
        sort(a + 1, a + P + 1, [](Point &a, Point &b){
            return a.s < b.s;
        });
        f[0] = inf, ans = inf;
        dfs(0, 0);
        cout << ans << "\n";
    }
    return 0;
}