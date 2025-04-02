#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int n, s, tot, ans;
struct Node
{
    int h, id;
};
Node nodes[maxn*maxn];
int vis[maxn];
int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            int h;
            cin >> h;
            nodes[++tot] = {h, i};
        }
    }
    sort(nodes+1, nodes+tot+1, [](Node a, Node b) { return a.h < b.h; });
    int cnt = 0, r = 0;
    ans = 1e9;
    for (int i = 1; i <= tot; i++)
    {
        while (cnt < n && r < tot)
        {
            if (!vis[nodes[++r].id]) cnt++;
            vis[nodes[r].id]++;
        }
        if (cnt == n)
        {
            // cout << i << " " << r << "\n";
            ans = min(ans, nodes[r].h - nodes[i].h);
        }
        vis[nodes[i].id]--;
        if (vis[nodes[i].id] == 0) cnt--;
    }
    cout << ans;
    return 0;
}