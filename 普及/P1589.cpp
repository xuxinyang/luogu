#include <bits/stdc++.h>
using namespace std;

int n, l, ans;
struct Road
{
    int s, e;
};
bool cmp(Road x, Road y)
{
    return x.s < y.s;
}
Road roads[10005];
int main()
{
    cin >> n >> l;
    for (int i = 1; i <= n; i++) cin >> roads[i].s >> roads[i].e;
    sort(roads + 1, roads + n + 1, cmp);
    int x = 0;
    for (int i = 1; i <= n; i++)
    {
        x = max(x, roads[i].s);
        while (x < roads[i].e) x += l, ans++;
    }
    cout << ans << endl;
    return 0;
}