#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, m, f[maxn][maxn], cost[maxn][maxn]; 
struct Node
{
    int path[maxn];
    int tail;
};
Node nodes[maxn][maxn];
int main()
{
    memset(f, 0xc0, sizeof(f));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> cost[i][j];
        }
    }
    for (int i = 0; i <= m; i++) f[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= m; j++)
        {
            if (f[i-1][j-1] + cost[i][j] > f[i][j-1])
            {
                nodes[i][j] = nodes[i-1][j-1];
                nodes[i][j].path[++nodes[i][j].tail] = j;
                f[i][j] = f[i-1][j-1] + cost[i][j];
            }
            else
            {
                nodes[i][j] = nodes[i][j-1];
                f[i][j] = f[i][j-1];
            }
        }
    }
    cout << f[n][m] << endl;
    for (int i = 1; i <= nodes[n][m].tail; i++)
    {
        cout << nodes[n][m].path[i] << " ";
    }
    return 0;
}