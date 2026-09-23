#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N = 2505;
int n, m, k;
ll s[N], dis[N], best[N][3], ans;
bool can[N][N];
vector<int> g[N];
void bfs(int st)
{
    memset(dis, -1, sizeof dis);
    queue<int> q;
    q.push(st);
    dis[st] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (dis[u] == k+1) continue;
        for (int v : g[u])
        {
            if (dis[v]==-1)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dis[i]!=-1 && dis[i] <= k+1) can[st][i] = 1;   // 可达
    }
}
void add(int x, int p)
{
    for (int i = 0; i < 3; i++)
    {
        if (best[x][i] == 0 || s[p] > s[best[x][i]])
        {
            for (int j = 2; j > i; j--)
            {
                best[x][j] = best[x][j-1];
            }
            best[x][i] = p;
            break;
        }
    }
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 2; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) bfs(i);
    for (int x = 2; x <= n; x++)
    {
        for (int p = 2; p <= n; p++)
        {
            if (p == x) continue;
            if (can[1][p] && can[p][x]) add(x, p);
        }
    }
    for (int B = 2; B <= n; B++)
    {
        for (int C = 2; C <= n; C++)
        {
            if (B == C || !can[B][C]) continue;
            for (int i = 0; i < 3; i++)
            {
                int A = best[B][i];
                if (A == 0) continue;
                for (int j = 0; j < 3; j++)
                {
                    int D = best[C][j];
                    if (D == 0) continue;
                    if (A == B || A == C || A == D
                    || B == C || B == D || C == D) continue;
                    ans = max(ans, s[A]+s[B]+s[C]+s[D]);
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}