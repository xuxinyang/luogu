#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
struct Pos
{
    int sx, sy, ex, ey;
}pos[105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> x >> y;
    int x1, y1, x2, y2, tx, ty, sum, cir;
    for (int i = 1; i <= x; i++)
    {
        cin >> pos[i].sx >> pos[i].sy >> pos[i].ex >> pos[i].ey;
    }
    for (int i = 1; i <= y; i++)
    {
        cin >> tx >> ty;
        sum = 0;
        for (int j = 1; j <= x; j++)
        {
            if (tx >= pos[j].sx && tx <= pos[j].ex &&
            ty >= pos[j].sy && tx <= pos[j].ey)
            {
                sum++;
                cir = j;
            }
        }
        if (sum != 0)
        {
            cout << "Y " << sum << " " << cir << "\n";
        }
        else cout << "N\n";
    }
    return 0;
}