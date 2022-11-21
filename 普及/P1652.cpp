#include <bits/stdc++.h>
using namespace std;
int x[55], y[55], r[55], n, ans;
double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int main()
{
    int sx, sy, dx, dy;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) cin >> y[i];
    for (int i = 1; i <= n; i++) cin >> r[i];
    cin >> sx >> sy >> dx >> dy;
    for (int i = 1; i <= n; i++)
    {
        if ((dist(sx, sy, x[i], y[i]) < r[i]) ^ (dist(dx, dy, x[i], y[i]) < r[i])) ans++;
    }
    cout << ans << endl;
    return 0;
}