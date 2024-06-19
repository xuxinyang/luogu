#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n, m, k;
int row[maxn], col[maxn];
long long ans = 0;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= k; j+=i)
            row[j]++;
    for (int i = 1; i <= m; i++)
        for (int j = i; j <= k; j+=i)
            col[j]++;
    for (int i = 1; i <= k; i++)
        ans += 1ll * i * row[i] * col[i];
    cout << ans;
    return 0;
}