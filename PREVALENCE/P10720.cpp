#include <bits/stdc++.h>
using namespace std;
const int maxp = 1e6+5;
int n, x, p, prime[maxp];
bool isPrime[maxp];
void init()
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    for (int i = 1; i*i <= maxp; i++)
    {
        if (isPrime[i])
        {
            for (int j = i*2; j < maxp; j+=i)
                isPrime[j] = 0;
        }
    }
    for (int i = 2; i < maxp; i++)
        if (isPrime[i]) prime[++p] = i;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    init();
    for (int i = 1; i <= n; i++)
    {
        unordered_map<int, int> ump;
        cin >> x;
        for (int j = 1; x!= 1; j++)
        {
            while (x % prime[j] == 0) ump[j] = 1, x /= prime[j];
        }
        if (ump.size() == 2) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}