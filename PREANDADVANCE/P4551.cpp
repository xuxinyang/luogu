#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5+5;
struct Edge{
    int to, w;
};
int s[N], trie[N*31][2];
vector<Edge> ve[N];
int n, tot;
void dfs(int u, int fa)
{
    for (auto e : ve[u])
    {
        int v = e.to, w = e.w;
        if (v == fa) continue;
        s[v] = s[u] ^ w;
        dfs(v, u);
    }
}
void insert(int val)
{
    int x = 0;
    for (int i = (1<<30); i; i >>= 1)
    {
        int a = bool(val & i);
        if (!trie[x][a]) trie[x][a] = ++tot;
        x = trie[x][a];
    }
}
int find(int val)
{
    int ans = 0, x = 0;
    for (int i = (1<<30); i; i >>= 1)
    {
        int a = bool(val & i);
        if (trie[x][!a])
        {
            ans += i;
            x = trie[x][!a];
        }
        else x = trie[x][a];
    }
    return ans;
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ve[u].push_back({v, w});
        ve[v].push_back({u, w});
    }
    dfs(1, -1);
    for (int i = 1; i <= n; ++i) insert(s[i]);
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, find(s[i]));
    cout << ans;
    
    return 0;
}