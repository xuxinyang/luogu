#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
int n, m, mp[maxn][maxn], sx, sy, ex, ey;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
char d;
bool vis[maxn][maxn];
struct Node
{
    int x, y, tim, dire;
};
Node nodes[maxn*maxn];
queue<Node> q;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }
    cin >> sx >> sy >> ex >> ey >> d;
    q.push(Node{sx, sy, 0, d});
    while (!q.empty())
    {

    }
    return 0;
}