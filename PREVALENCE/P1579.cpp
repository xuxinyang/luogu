#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4+5;
int n, prime[maxn], p;
bool isPrime[maxn];
void genPrime()
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            prime[++p] = i;
            for (int j = i*2; j <= n; j+=i)
            {
                isPrime[j] = 0;
            }
        }
    }
}
int main()
{
    cin >> n;
    genPrime();
    for (int i = 1; i <= p; i++)
    {
        for (int j = i; j <= p; j++)
        {
            int k = n - prime[i] - prime[j];
            if (isPrime[k] && k > 0)
            {
                cout << prime[i] << " " << prime[j] << " " << k;
                return 0;
            }
        }
    }
    return 0;
}