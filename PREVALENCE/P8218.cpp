#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, m, a[maxn], s[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l, r;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    cin >> m;
    while (m--)
    {
        cin >> l >> r;
        cout << s[r] - s[l-1] << "\n";
    }
    return 0;
}