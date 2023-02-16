#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, b, ans = INT_MAX, x1, x2;
struct Grass
{
    int s, j;
};
Grass grasses[maxn];
bool cmp(Grass x, Grass y)
{
    return x.j < y.j;
}
int main()
{
    cin >> n >> b;
    grasses[0].j = b;
    for (int i = 1; i <= n; i++) cin >> grasses[i].s >> grasses[i].j;
    sort(grasses + 1, grasses + n + 1, cmp);
    x1 = upper_bound(grasses + 1, grasses + n + 1, grasses[0], cmp) - grasses;
    x2 = x1 - 1;
    for (int i = x1, j = x2; i <= n && j > 0; ++i)
    {
        while (j > 0 && grasses[j].s < grasses[i].j - grasses[j].j) --j;
        if (j > 0) ans = min(ans, max(0, grasses[i].j-grasses[j].j-grasses[i].s));
    }
    for (int i = x1, j = x2; i <= n && j > 0; --j)
    {
        while (i <= n && grasses[i].s < grasses[i].j-grasses[j].j) ++i;
        if (i <= n) ans = min(ans, max(0, grasses[i].j-grasses[j].j-grasses[j].s));
    }
    cout << (ans == INT_MAX ? -1: ans);
    return 0;
}