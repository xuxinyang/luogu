#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int n, m, u, v, s, tot;
int mp[maxn][maxn], de[maxn], path[maxn];
void dfs(int u)
{
    for (int i = 1; i <= n; i++)
    {
        if (mp[u][i] >= 1)
        {
            mp[u][i]--;
            mp[i][u]--;
            dfs(i);
        }
    }
    path[++tot] = u;
}
int main()
{
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        mp[u][v]++;
        mp[v][u]++;
        de[u]++, de[v]++;
        n = max(n, max(u, v));
    }
    s = 1;
    for (int i = 1; i <= n; i++)
    {
        if (de[i] % 2 == 1)
        {
            s = i;
            break;
        }
    }
    dfs(s);
    for (int i = tot; i >= 1; i--) cout << path[i] << "\n";
    return 0;
}