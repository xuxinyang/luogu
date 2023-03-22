#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
const int maxm = 2e3+5;
int n, a, b;
double g[maxn][maxn], x[maxn], y[maxn], dist[maxn], A, B;
bool st[maxn], vis[maxn][maxn];
double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}
void dijkstra()
{
    for (int i = 0; i <= n+1; i++) dist[i] = 0x3f3f3f3f;
    dist[0] = 0;
    for (int i = 0; i <= n + 1; i++)
    {
        int t = -1;
        for (int j = 0; j <= n + 1; j++)
        {
            if (!st[j] && (t == -1 || dist[t] > dist[j])) t = j;
        }
        for (int j = 0; j <= n + 1; j++)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
        st[t] = true;
    }
    cout << fixed << setprecision(4) << dist[n+1];
}
int main()
{
    cin >> A >> B >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    while (cin >> a >> b && (a != 0 && b != 0))
    {
        vis[a][b] = vis[b][a] = true;
        g[a][b] = g[b][a] = B * distance(x[a], y[a], x[b], y[b]);
    }
    cin >> x[0] >> y[0] >> x[n+1] >> y[n+1];
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (!vis[i][j])
                g[i][j] = g[j][i] = A * distance(x[i], y[i], x[j], y[j]);
        }
    }
    dijkstra();
    return 0;
}