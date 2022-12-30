#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+5;
int n, len;
struct Stick
{
    int l, w;
};
Stick sticks[maxn], f[maxn];
bool cmp(Stick x, Stick y)
{
    if (x.l != y.l) return x.w >= y.w;
    return x.l > y.l;
}
bool operator < (Stick x, Stick y)
{
    if (x.l == y.l) return x.w < y.w;
    else return x.l < y.l;
}
int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> sticks[i].l >> sticks[i].w;
    }
    sort(sticks + 1, sticks + n + 1, cmp);
    f[1] = sticks[1];
    len = 1;
    for (int i = 2; i <= n; i++)
    {
        if (sticks[i].l == f[len].l) continue;
        if (sticks[i].l > f[len].l) f[++len] = sticks[i];
        else *lower_bound(f+1, f+len+1, sticks[i]) = sticks[i];
    }
    // for (int i = 1; i <= len; i++)
    // {
    //     cout << f[i].l << " " << f[i].w << "\n";
    // }
    cout << len << endl;
    return 0;
}