#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
struct Node
{
    int l, r, c;
}nodes[N];
int n;
bool vis[N];
bool cmp(Node x, Node y)
{
    return x.r < y.r;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> nodes[i].l >> nodes[i].r >> nodes[i].c;
    sort(nodes+1, nodes+n+1, cmp);
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = nodes[i].l; j <= nodes[i].r; j++)
        {
            if (vis[j]) cnt++;
        }
        if (cnt < nodes[i].c)
        {
            int t = nodes[i].c - cnt;
            for (int j = nodes[i].r; t; j--)
            {
                if (!vis[j]) vis[j]=1, t--;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= nodes[n].r; i++)
    {
        if (vis[i]) cnt++;
    }
    cout << cnt;
    return 0;
}