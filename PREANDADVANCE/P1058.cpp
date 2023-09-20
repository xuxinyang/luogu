#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const char rect[10][10] = {
    "..+---+",
    "./   /|",
    "+---+ |",
    "|   | +",
    "|   |/.",
    "+---+.."};
char c[maxn][maxn];
int n, m, a[55][55], maxx, maxy;
inline void copytoc(int x, int y)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (rect[i][j] != '.')
                c[x + i][y + j] = rect[i][j];
        }
    }
}
inline void draw()
{
    int h = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            h = max(h, 1 - ((i - 1) * 2 + 1 - (a[i][j] - 1) * 3));
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= a[i][j]; k++)
            {
                int fx = (i - 1) * 2 + 1 - (k - 1) * 3 + h;
                int fy = (n - i) * 2 + (j == 1 ? 1 : (j - 1) * 4 + 1);
                copytoc(fx, fy);
            }
        }
    }
    maxx = 2 * n + 4 + h;
    maxy = 4 * m + 1 + 2 * n;
}
int main()
{
    cin >> n >> m;
    memset(c, '.', sizeof(c));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    draw();
    for (int i = 1; i <= maxx; i++)
    {
        for (int j = 1; j <= maxy; j++)
        {
            cout << c[i][j];
        }
        cout << "\n";
    }
    return 0;
}