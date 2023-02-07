#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e3+5;
char ch;
ll l[maxn], r[maxn], h[maxn], k[maxn], n, m, top;
int d[maxn][maxn];
ll ans;
void orderStackLeft()
{
    top = 0;
    for (int i = m; i >= 1; i--)
    {
        while (top != 0 && h[i] <= h[k[top]])
            l[k[top]] = i, top--;
        top++;
        k[top] = i;
    }
    while (top) l[k[top]] = 0, top--;
}
void orderStackRight()
{
    top = 0;
    for (int i = 1; i <= m; i++)
    {
        while (top != 0 && h[i] < h[k[top]])
            r[k[top]] = i, top--;
        top++;
        k[top] = i;
    }
    while (top) r[k[top]] = m+1, top--;
}
void solve()
{
    orderStackLeft();
    orderStackRight();
    for (int i = 1; i <= m; i++)
        ans += (i-l[i])*(r[i]-i) * h[i];
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ch;
            if (ch == '*') d[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            h[j]++;
            if (d[i][j]) h[j] = 0;
        }
        solve();
    }
    cout << ans << endl;
    return 0;
}