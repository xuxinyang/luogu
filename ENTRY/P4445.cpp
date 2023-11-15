#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
#define ll long long
ll ans;
int n, a[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) ans += max(a[i], a[i-1]);
    cout << ans;
    return 0;
}