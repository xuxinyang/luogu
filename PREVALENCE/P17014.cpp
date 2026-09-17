#include <bits/stdc++.h>
using namespace std;
// 染色：并查集
constexpr int N = 1e5+5;
int t, n, color[N], cnt;
vector<int> ve[N]; 
void dfs(int u, int c)
{
    color[u] = c;
    cnt++;
    for (auto v : ve[u])
    {
        if (!color[v])
        {
            dfs(v, c);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) ve[i].clear();
        for (int i = 1; i <= n; i++)
        {
            int u, v;
            cin >> u >> v;
            color[i] = 0;
            ve[u].push_back(v);
            ve[v].push_back(u);
        }
        int mx = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!color[i])
            {
                cnt = 0;
                dfs(i, i);
                int p = (cnt%2==0?2:3);
                mx = max(mx, p);
                // cout << cnt << " ";
            }
        }
        cout << mx << "\n";
    }
    return 0;
}