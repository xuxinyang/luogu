#include <bits/stdc++.h>
using namespace std;

int v, x, y;
bool vis[205][205];
queue<array<int, 3>> q;
int main()
{
    cin >> v >> x >> y;
    q.push({v, 0, 0});
    vis[v][0] = 1;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        int a = cur[0], b = cur[1], step = cur[2];
        int c = v - a - b;

        if (a * 2 == v || b * 2 == v || c * 2 == v)
        {
            cout << step;
            return 0;
        }

        int na, nb, nc, pour;

        // a -> b
        pour = min(a, x - b);
        na = a - pour;
        nb = b + pour;
        if (!vis[na][nb])
        {
            vis[na][nb] = 1;
            q.push({na, nb, step + 1});
        }

        // a -> c
        pour = min(a, y - c);
        na = a - pour;
        nc = c + pour;
        nb = b; // b 不变
        if (!vis[na][nb])
        {
            vis[na][nb] = 1;
            q.push({na, nb, step + 1});
        }

        // b -> a
        pour = min(b, v - a);
        na = a + pour;
        nb = b - pour;
        if (!vis[na][nb])
        {
            vis[na][nb] = 1;
            q.push({na, nb, step + 1});
        }

        // b -> c
        pour = min(b, y - c);
        nb = b - pour;
        nc = c + pour;
        na = a;
        if (!vis[na][nb])
        {
            vis[na][nb] = 1;
            q.push({na, nb, step + 1});
        }

        // c -> a
        pour = min(c, v - a);
        na = a + pour;
        nc = c - pour;
        nb = b;
        if (!vis[na][nb])
        {
            vis[na][nb] = 1;
            q.push({na, nb, step + 1});
        }

        // c -> b
        pour = min(c, x - b);
        nb = b + pour;
        nc = c - pour;
        na = a;
        if (!vis[na][nb])
        {
            vis[na][nb] = 1;
            q.push({na, nb, step + 1});
        }
    }

    cout << -1;
    return 0;
}
