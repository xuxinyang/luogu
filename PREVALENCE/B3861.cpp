#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int n, son[maxn];
vector<int> edges[maxn];
void dfs(int u, int f)
{
    for (int i = 0; i < edges[u].size(); i++)
    {
        if (edges[u][i] == f) continue;
        dfs(edges[u][i], u);
        son[u] += son[edges[u][i]];
    }
}
int main()
{
    int x;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> x;
        edges[x].push_back(i + 1);
        edges[i + 1].push_back(x);
    }
    for (int i = 1; i <= n; i++) son[i] = 1;
    dfs(1, 0);
    for (int i = 1; i <= n; i++) cout << son[i] << endl;
    return 0;
}