#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e3 + 5;
const ll inf = LLONG_MAX;
struct Node
{
    ll l, r, h, id;
};
ll n, dp[maxn][2], s, t;
Node nodes[maxn];
bool cmp(Node x, Node y)
{
    if (x.h == y.h)
        return x.l < y.l;
    return x.h > y.h;
}
int main()
{
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> nodes[i].l >> nodes[i].r >> nodes[i].h;
        nodes[i].id = i;
        dp[i][0] = dp[i][1] = inf;
    }
    sort(nodes + 1, nodes + n + 1, cmp);
    int start, target;
    for (int i = 1; i <= n; i++)
    {
        if (nodes[i].id == s)
            start = i;
        if (nodes[i].id == t)
            target = i;
    }
    dp[start][0] = 0, dp[start][1] = nodes[start].r - nodes[start].l;
    ll ans = inf;
    for (int i = start; i <= target; i++)
    {
        for (int j = i + 1; j <= target; j++)
        {
            if (nodes[i].l >= nodes[j].l && nodes[i].l <= nodes[j].r && nodes[i].h > nodes[j].h)
            {
                ll val = nodes[i].h - nodes[j].h;
                if (j == target)
                    ans = min(ans, dp[i][0] + val);
                dp[j][0] = min(dp[j][0], dp[i][0] + nodes[i].l - nodes[j].l + val);
                dp[j][1] = min(dp[j][1], dp[i][0] + nodes[j].r - nodes[i].l + val);
                break;
            }
        }
        for (int j = i + 1; j <= target; j++)
        {
            if (nodes[i].r >= nodes[j].l && nodes[i].r <= nodes[j].r && nodes[i].h > nodes[j].h)
            {
                ll val = nodes[i].h - nodes[j].h;
                if (j == target)
                    ans = min(ans, dp[i][1] + val);
                dp[j][0] = min(dp[j][0], dp[i][1] + nodes[i].r - nodes[j].l + val);
                dp[j][1] = min(dp[j][1], dp[i][1] + nodes[j].r - nodes[i].r + val);
                break;
            }
        }
    }
    cout << ans;
    if (ans == inf)
        cout << "-1";
    else
        cout << ans;
    return 0;
}