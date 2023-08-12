#include <bits/stdc++.h>
using namespace std;
int ans, n, k, m, g[105][105];
void dfs(int x, int t)
{
    
}
int main()
{
    int a, b;
    cin >> n >> k >> m;
    for (int i = 1; i <= k; i++)
    {
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}