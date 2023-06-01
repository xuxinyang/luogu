#include <bits/stdc++.h>
using namespace std;
int n, x;
const int maxn = 1e5+5;
bool isPrime[maxn];
// bool isPrime(int x)
// {
//     if (x < 2) return 0;
//     for (int i = 2; i * i <= x; i++)
//     {
//         if (x % i == 0) return 0;
//     }
//     return 1;
// }
void prime()
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= (int)1e5; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * 2; j <= int(1e5); j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
}
int main()
{
    cin >> n;
    prime();
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (isPrime[x]) cout << x << " ";
    }
    return 0;
}