#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7+5;
int a, b;
bool isPrime[maxn];
bool isPalindromes(int x)
{
    int sum = 0;
    int p = x;
    while (p)
    {
        sum = sum * 10 + p % 10;
        p /= 10;
    }
    return sum == x;
}
int main()
{
    cin >> a >> b;
    if (b > 1e7) b = 1e7;
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= 1e7; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 1e7; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    for (int i = a; i <= b; i++)
    {
        if (isPrime[i] && isPalindromes(i))
        {
            cout << i << "\n";
        }
    }
    return 0;
}