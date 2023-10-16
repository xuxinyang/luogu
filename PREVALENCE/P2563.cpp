#include <bits/stdc++.h>
using namespace std;
int n, prime[205], dp[205], tot;
bool isPrime[205];
void init()
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i*i <= 200; i++)
    {
        if (isPrime[i])
        {
            prime[++tot] = i;
            for (int j = i*2; j <= 200; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    for (int i = sqrt(200)+1; i <= 200; i++)
    {
        if (isPrime[i]) prime[++tot] = i;
    }
}
int main()
{
    init();
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n)
    {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= tot; i++)
        {
            for (int j = prime[i]; j <= n; j++)
            {
                dp[j] += dp[j-prime[i]];
            }
        }
        cout << dp[n] << "\n";
    }
    return 0;
}