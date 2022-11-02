#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1505;
queue<int> q;
int d[MAXN], mp[MAXN][MAXN];
int n, m;

void bfs()
{
    memset(d, -1, sizeof(d));
    d[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (mp[t][i] && d[i] < d[t] + mp[t][i])
            {
                d[i] = d[t] + mp[t][i];
                q.push(i);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int s, e, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> s >> e >> v;
        mp[s][e] = max(mp[s][e], v);    // 只保留两点之前权值最大的那条边，也就是最长的那条边
    }
    bfs();
    cout << d[n] << endl;   // 输出最后一点的最长路即可
    return 0;
}