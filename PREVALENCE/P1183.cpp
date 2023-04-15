#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2+5;
int n, ans;
struct Coord
{
    int x, y;
};
Coord coords[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> coords[i].x >> coords[i].y;
    }
    coords[n+1] = Coord{coords[1].x, coords[1].y};
    for (int i = 1; i <= n; i++)
    {
        ans += coords[i].x * coords[i+1].y - coords[i+1].x*coords[i].y;
    }
    cout << abs(ans) / 2;
    return 0;
}