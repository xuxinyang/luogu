#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+5;
const int maxm = 30;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll amax[maxn][maxm], amin[maxn][maxm], aneg[maxn][maxm], apos[maxn][maxm];
ll bmax[maxn][maxm], bmin[maxn][maxm];
ll lg[maxn], n, m, q, x;
void update(ll &a, ll b)
{
    if (a < b) a = b;
}
int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        amax[i][0] = amin[i][0] = x;
        aneg[i][0] = (x<0?x:-inf);
        apos[i][0] = (x>=0?x:inf);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        bmax[i][0] = bmin[i][0] = x;
    }
    for (int i = 2; i <= max(n, m); i++)
        lg[i] = lg[i>>1]+1;
    for (int j = 1; j <= lg[n]; j++)    // 构建A相关ST表
    {
        for (int i = 1; i+(1<<j)-1<=n; i++)
        {
            int p = i+(1<<(j-1));
            amax[i][j] = max(amax[i][j-1], amax[p][j-1]);
            aneg[i][j] = max(aneg[i][j-1], aneg[p][j-1]);
            amin[i][j] = min(amin[i][j-1], amin[p][j-1]);
            apos[i][j] = min(apos[i][j-1], apos[p][j-1]);
        }
    }
    for (int j = 1; j <= lg[m]; j++)    // 构建B相关ST表
    {
        for (int i = 1; i+(1<<j)-1<=m; i++)
        {
            int p = i + (1<<(j-1));
            bmax[i][j] = max(bmax[i][j-1], bmax[p][j-1]);
            bmin[i][j] = min(bmin[i][j-1], bmin[p][j-1]);
        }
    }
    while (q--)
    {
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        ll lga = lg[r1-l1+1], lgb = lg[r2-l2+1];
        ll pa = r1-(1<<lga)+1, pb = r2-(1<<lgb)+1;
        ll maxa = max(amax[l1][lga], amax[pa][lga]);
        ll mina = min(amin[l1][lga], amin[pa][lga]);
        ll nega = max(aneg[l1][lga], aneg[pa][lga]);
        ll posa = min(apos[l1][lga], apos[pa][lga]);
        ll maxb = max(bmax[l2][lgb], bmax[pb][lgb]);
        ll minb = min(bmin[l2][lgb], bmin[pb][lgb]);
        ll ans = -inf;
        update(ans, maxa*(maxa>=0?minb:maxb));
        update(ans, mina*(mina>=0?minb:maxb));
        if (nega != -inf) update(ans, nega*(nega>=0?minb:maxb));
        if (posa != inf) update(ans, posa*(posa>=0?minb:maxb));
        cout << ans << "\n";
    }
    return 0;
}