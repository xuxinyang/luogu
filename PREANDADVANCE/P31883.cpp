#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6+5;
int n, m, f[N], rd[N];
vector<int> ve[N];
int topo()
{
    int ans = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!rd[i] && ve[i].size())
        {
            q.push(i), f[i] = 1;
        }
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (!ve[x].size()) ans += f[x];
        for (auto v : ve[x])
        {
            f[v] += f[x], rd[v]--;
            if (!rd[v]) q.push(v);
        }
    }
    return ans;
}
int main()
{
    cin.tie(nullptr) -> sync_with_stdio(false);
    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        rd[y]++;
        ve[x].push_back(y);
    }
    cout << topo();
    return 0;
}