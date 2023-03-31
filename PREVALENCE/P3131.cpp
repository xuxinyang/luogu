#include <bits/stdc++.h>
using namespace std;

int n, x, s;
int l[7] = {0, -1, -1, -1, -1, -1, -1}, r[7], ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        s = (s + x) % 7;
        if (l[s] == -1) l[s] = i;
        r[s] = i;
    }
    for (int i = 0; i < 7; ++i)
        if (l[i] != -1) ans = max(ans, r[i] - l[i]);
    cout << ans << endl;
    return 0;
}