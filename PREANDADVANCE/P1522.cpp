#include <bits/stdc++.h>
using namespace std;
const int maxn = 155;
const double inf = 1e20;
struct Node
{
    int x;
    int y;
    double distance(const Node &node)
    {
        return sqrt(pow(x - node.x, 2) + pow(y - node.y, 2));
    }
};
Node nodes[maxn];
int n, f[maxn];
double dist[maxn], w[maxn][maxn], ans[maxn], maxx, minx = inf;
string s;
void dfs(int i, int id)
{
    f[i] = id;
    for (int j = 1; j <= n; j++)
        if (!f[j] && w[i][j] < inf) dfs(j, id);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> nodes[i].x >> nodes[i].y;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        s = " " + s;
        for (int j = 1; j < s.length(); j++)
        {
            if (s[j] == '1' || i == j)
                w[i][j] = nodes[i].distance(nodes[j]);
            else
                w[i][j] = inf;
        }
    }
    int id = 1;
    for (int i = 1; i <= n; i++)
        if (!f[i]) dfs(i, id++);
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (w[i][j] > w[i][k] + w[k][j])
                    w[i][j] = w[i][k] + w[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (w[i][j] < inf) ans[i] = max(ans[i], w[i][j]);
        dist[f[i]] = max(dist[f[i]], ans[i]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            if (f[i] != f[j])
            {
                maxx = max(max(dist[f[i]], dist[f[j]]), 
                ans[i] + ans[j] + nodes[i].distance(nodes[j]));
                minx = min(minx, maxx);
            }
        }
    cout << fixed << setprecision(6) << minx << "\n";
    return 0;
}