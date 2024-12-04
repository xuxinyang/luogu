#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int t, n, flag;
double h, r;
struct Node
{
    double x, y, z;
};
Node nodes[maxn];
bool vis[maxn];
double dist(Node A, Node B)
{
    return sqrt(pow(A.x-B.x, 2) + pow(A.y-B.y, 2) + pow(A.z-B.z, 2));
}
bool check(Node A, Node B)
{
    return dist(A, B) <= 2*r;
}
void dfs(int u)
{
    if (nodes[u].z + r >= h)
    {
        flag = 1;
        return;
    }
    vis[u] = 1;
    for (int v = 1; v <= n; v++)
    {
        if (!vis[v] && check(nodes[u], nodes[v]))
        {
            dfs(v);
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
        cin >> n >> h >> r;
        for (int i = 1; i <= n; i++)
            cin >> nodes[i].x >> nodes[i].y >> nodes[i].z;
        memset(vis, 0, sizeof(vis));
        flag = 0;
        sort(nodes+1, nodes+n+1, [](Node A, Node B){
            return A.z < B.z;
        });
        for (int i = 1; i <= n; i++)
        {
            if (flag) break;
            if (nodes[i].z > r) break;
            dfs(i);
        }
        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}