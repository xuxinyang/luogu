#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define ll long long
const int maxn = 1e5+5;
ll dist(int x1, int y1, int x2, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
ll n, ans1, ans2;
struct Node
{
    ll d1, d2;
};
Node dis[maxn];
bool cmp(Node A, Node B)
{
    return A.d1 < B.d1;
}
int main()
{
    ll x1, y1, x2, y2, x, y;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        dis[i].d1 = dist(x1, y1, x, y);
        dis[i].d2 = dist(x2, y2, x, y);
    }
    sort(dis + 1, dis + n + 1, cmp);
    ans1 = dis[n].d1, ans2 = 0;
    for (int i = n-1; i >= 1; i--)
    {
        ans2 = max(ans2, dis[i+1].d2);
        ans1 = min(ans1, ans2 + dis[i].d1);
    }
    cout << ans1;
    return 0;
}