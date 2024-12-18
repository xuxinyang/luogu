#include <bits/stdc++.h>
using namespace std;
int w, s, p, b, e;
unordered_map<int, int> ump;
unordered_map<int, bool> vis;
void init()
{
    ump.clear();
    vis.clear();
    for (int i = 1; i <= p; i++)
    {
        cin >> b >> e;
        ump[b] = e;
    }
}
struct Pos
{
    int pos, step;
};
void bfs()
{
    init();
    queue<Pos> q;
    q.push(Pos{0, 0});
    vis[0] = 1;
    while (!q.empty())
    {
        Pos pos = q.front();
        q.pop();
        if (pos.pos == w)
        {
            cout << pos.step << "\n";
            break;
        }
        for (int i = 1; i <= s; i++)
        {
            if (vis.count(pos.pos + i) == 0)
            {
                vis[pos.pos+i] = 1;
                if (ump.count(pos.pos+i) != 0)
                {
                    vis[ump[pos.pos+i]] = 1;
                    q.push(Pos{ump[pos.pos+i], pos.step+1});
                }
                else q.push(Pos{pos.pos+i, pos.step+1});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> w)
    {
        if (w == 0) break;
        cin >> s >> p;
        bfs();
    }
    return 0;
}