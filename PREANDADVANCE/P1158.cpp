#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
const int maxn = 1e5+5;
ll dist(int x1, int y1, int x2, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
ll n, ans1, ans2, ansa, ansb;
struct Node
{
    int x, y;
};
Node pos[maxn];
bool cmp(Node A, Node B)
{
    return 
}
int main()
{
    ll x1, y1, x2, y2, x, y;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        ll cur1 = dist(x1, y1, x, y);
        ll cur2 = dist(x2, y2, x, y);
        ansa = max(cur1, ansa);
        ansb = max(cur2, ansb);
        if (cur1 < cur2 && cur1 > ans1 && ans2 < cur2) ans1 = cur1;
        if (cur1 > cur2 && cur2 > ans2 && ans1 < cur1) ans2 = cur2;
    }
    cout << min(min(ansa, ansb), ans1 + ans2);
    return 0;
}