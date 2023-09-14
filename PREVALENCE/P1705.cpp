#include <bits/stdc++.h>
using namespace std;
int r, m, n, a[35], ans;
bool vis[35];
void dfs(int idx, int cnt, int sum)
{
    if (m - idx + 1 < r - cnt) return;
    if (cnt == r)
    {
        if (sum > n) ans++;
        return;
    }
    for (int i = idx; i <= m; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(i+1, cnt+1, sum + a[i]);
            vis[i] = 0;
        }
    }
}
int main()
{
    cin >> m >> r >> n;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    dfs(1, 0, 0);
    cout << ans;
    return 0;
}