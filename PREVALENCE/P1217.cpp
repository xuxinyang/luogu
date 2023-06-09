#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7+5;
int a, b;
bool is_prime[maxn];
bool is_palindrome(int x)
{
    int s = 0, p = x;
    while (p)
    {
        s = s * 10 + p % 10;
        p /= 10;
    }
    return s == x;
}
int main()
{
    cin >> a >> b;
    if (a >= 1e7) a = 1e7;
    if (b >= 1e7) b = 1e7;
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= 1e7; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= 1e7; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }
    for (int i = a; i <= b; i++)
    {
        if (is_prime[i] && is_palindrome(i))
        {
            cout << i << "\n";
        }
    }
    return 0;
}