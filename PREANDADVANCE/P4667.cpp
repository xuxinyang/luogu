#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int dx[4] = {1, -1, -1, 1};
const int dy[4] = {1, 1, -1, -1};
const int fx[4] = {0, -1, -1, 0};
const int fy[4] = {0, 0, -1, -1};
const string t = "\\/\\/";
int n, m, d[N][N];
char c[N][N];
deque<pair<int, int>> dq;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cin >> c[i][j];
    }
    if ((n+m) % 2 == 1)
    {
        cout << "NO SOLUTION\n";
        return 0;
    }
    memset(d, 0x3f, sizeof(d));
    d[1][1] = 0;
    dq.push_back({1, 1});
    while (!dq.empty())
    {
        auto [x, y] = dq.front(); dq.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            int gx = x + fx[i], gy = y + fy[i];
            if (nx >= 1 && nx <= n+1 && ny >= 1 && ny <= m+1)
            {
                if (t[i] != c[gx][gy])
                {
                    int p = d[x][y] + 1;
                    if (p < d[nx][ny])
                    {
                        d[nx][ny] = p;
                        dq.push_back({nx, ny});
                    }
                }
                else
                {
                    int p = d[x][y];
                    if (p < d[nx][ny])
                    {
                        d[nx][ny] = p;
                        dq.push_front({nx, ny});
                    }
                }
            }
        }
    }
    cout << d[n+1][m+1];
    return 0;
}