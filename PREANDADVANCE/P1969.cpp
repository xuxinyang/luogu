#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, h[maxn], ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) if (h[i] > h[i-1]) ans += h[i]-h[i-1];
    cout << ans;
    return 0;
}