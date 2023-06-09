#include <bits/stdc++.h>
using namespace std;
int n;
bool isPrime(int x)
{
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0) return 0;
    }
    return 1;
}
int main()
{
    cin >> n;
    for (int i = 4; i <= n; i += 2)
    {
        for (int j = 2; j <= i/2; j++)
        {
            if (isPrime(j) && isPrime(i-j))
            {
                cout << i << "=" << j << "+" << i-j << "\n";
                break;
            }
        }
    }
    return 0;
}