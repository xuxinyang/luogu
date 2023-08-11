#include <bits/stdc++.h>
using namespace std;
int m, s, c, a[205], d[205], ans;
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    cin >> m >> s >> c;
    for (int i = 1; i <= c; i++) cin >> a[i];
    sort(a + 1, a + c + 1);
    for (int i = 2; i <= c; i++) d[i] = a[i]-a[i-1];
    sort(d + 2, d + c + 1, cmp);
    if (c <= m)
    {
        cout << c;
        return 0;
    }
    ans = a[c] - a[1] + 1;
    for (int i = 2; i < 1 + m; i++)
    {
        ans = ans - d[i] + 1;
    }
    cout << ans;
    return 0;
}