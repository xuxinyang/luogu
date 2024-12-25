#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6 + 5;
ll n;
ll cnt, pos, ans;
ll prime[maxn];
bool vis[maxn];
void init()
{
    vis[1] = true;
    for (int i = 2; i < maxn; i++)
    {
        if (!vis[i])
            prime[++pos] = i;
        for (int j = 1; j <= pos && i * prime[j] < maxn; j++)
        {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}
bool isPrime(ll x)
{
    if (x <= 1)
        return false;
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}
int main()
{
    init();
    cin >> n;
    if (isPrime(n))
    {
        cout << 1 << endl;
        return 0;
    }
    // cout << pos << endl;
    for (int i = 1; i <= pos; i++)
    {
        cnt = 0;
        while (n % prime[i] == 0)
        {
            n /= prime[i];
            cnt++;
        }
        if (cnt) ans += (-1+sqrt(1+8*cnt))/2;
        if (n == 1) break;
    }
    if (n > maxn) ans++;
    cout << ans;
    return 0;
}