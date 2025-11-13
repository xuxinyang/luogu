#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
#define ll long long
int n, prime[N], cnt;
bool vis[N];
void line_prime(int n)
{
    memset(vis, 1, sizeof vis);
    vis[0] = vis[1] = 0;
    for (ll i = 2; i <= n; i++)
    {
        if (vis[i]) prime[++cnt] = i;
        for (ll j = 1; j <= cnt && i*prime[j] <= n; j++)
        {
            vis[i*prime[j]] = 0;
            if (i % prime[j] == 0) break;
        }
    }
}
int main()
{
    cin >> n;
    line_prime(n);
    cout << cnt+1;
    return 0;
}