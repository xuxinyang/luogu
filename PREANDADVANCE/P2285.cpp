#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
int n, m, dp[maxn], ans;
struct Node
{
    int t, x, y;
};
Node nodes[maxn];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        dp[i] = 1;
        cin >> nodes[i].t >> nodes[i].x >> nodes[i].y;
    }
    for (int i = m; i > 1; i--)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            if (nodes[i].t - nodes[j].t >= abs(nodes[i].x-nodes[j].x)+abs(nodes[i].y-nodes[j].y))
            {
                dp[j] = max(dp[i]+1, dp[j]);
            }
        }
    }
    for (int i = 1; i <= m; i++) ans = max(dp[i], ans);
    cout << ans << endl;
    return 0;
}