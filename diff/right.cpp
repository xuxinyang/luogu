#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf = LLONG_MAX;
struct Node
{
    int l, r, h, id;
} nodes[1010];
int dp[1010][2];
bool cmp(Node x, Node y)
{
    if (x.h == y.h)
        return x.l < y.l;
    return x.h > y.h;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, os, ot;
    cin >> n >> os >> ot;
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
        if (nodes[i].id == os)
            start = i;
        if (nodes[i].id == ot)
            target = i;
    }
    dp[start][0] = 0, dp[start][1] = nodes[start].r - nodes[start].l;
    int ans = inf;
    for (int i = start; i <= target; i++)
    {
        for (int j = i + 1; j <= target; j++)
        {
            if (nodes[i].l >= nodes[j].l && nodes[i].l <= nodes[j].r && nodes[i].h > nodes[j].h)
            {
                int val = nodes[i].h - nodes[j].h;
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
                int val = nodes[i].h - nodes[j].h;
                if (j == target)
                    ans = min(ans, dp[i][1] + val);
                dp[j][0] = min(dp[j][0], dp[i][1] + nodes[i].r - nodes[j].l + val);
                dp[j][1] = min(dp[j][1], dp[i][1] + nodes[j].r - nodes[i].r + val);
                break;
            }
        }
    }
    if (ans == inf)
        cout << "-1\n";
    else
        cout << ans << '\n';
    return 0;
}