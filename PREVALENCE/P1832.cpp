#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e3+5;
ll n, prime[maxn], f[maxn], p;
bool isPrime[maxn];
void init()
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= 1000; i++)
    {
        if (isPrime[i])
        {
            prime[++p] = i;
            for (int j = i * 2; j <= 1000; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = sqrt(1000)+1; i <= 1000; i++)
    {
        if (isPrime[i]) prime[++p] = i; 
    }
}
int main()
{
    cin >> n;
    init();
    f[0] = 1;
    while (prime[p] > n) p--;
    // for (int i = 1; i <= p; i++) cout << prime[i] << " ";
    for (int i = 1; i <= p; i++)
    {
        for (int j = prime[i]; j <= n; j++)
        {
            f[j] += f[j-prime[i]];
        }
    }
    cout << f[n];
    return 0;
}