#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, m, a, b, mp[505][505];
vector<array<int, 2>> vea, veb;
queue<array<int, 3>> q;
int main()
{
    cin >> n >> m >> a >> b;
    memset(mp, 0x3f, sizeof(mp));
    for (int i = 1; i <= a; i++)
    {
        int x, y;
        cin >> x >> y;
        vea.push_back({x, y});
        q.push({x, y, 0});
        mp[x][y] = 0;
    }
    for (int i = 1; i <= b; i++)
    {
        int x, y;
        cin >> x >> y;
        veb.push_back({x, y});
    }
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = cur[0] + dx[i], y = cur[1] + dy[i], step = cur[2];
            if (x >= 1 && x <= n && y >= 1 && y <= m && step+1 < mp[x][y])
            {
                mp[x][y] = step+1;
                q.push({x, y, step+1});
            }
        }
    }
    for (auto cur : veb) cout << mp[cur[0]][cur[1]] << "\n";
    return 0;
}