#include <bits/stdc++.h>
using namespace std;
const int maxn = 1<<11;
int n, m;
int a[105][1005];
struct Node
{
    int s, step;
};
bool vis[maxn];
int spfa()
{
    int res;
    queue<Node> q;
    q.push(Node{(1<<n)-1, 0});
    vis[(1<<n)-1] = true;
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        if (cur.s == 0) return cur.step;
        for (int i = 1; i <= m; i++)
        {
            res = cur.s;
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == 1 && (res & (1<<j-1))) res ^= (1<<j-1);
                else if (a[i][j] == -1 && !(res & (1<<j-1))) res |= (1<<j-1);
            }
            if (!vis[res]) q.push(Node{res, cur.step+1}), vis[res] = 1;
        }
    }
    return -1;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    cout << spfa();   
    return 0;
}