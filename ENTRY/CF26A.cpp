#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i<= sqrt(x); i++)
    {
        if (x % i == 0) return false;
    }
    return true;
}
int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 6; i <= n; i++)
    {
        int tmp = 0;
        int x = i;
        for (int j = 2; j <= sqrt(x); j++)
        {
            if (x % j == 0 && isPrime(j))
            {
                tmp ++;
                
            }
            if (x % j == 0 && isPrime(x / j) && j != (x/j))
            {
                tmp++;
            }
        }
        if (tmp == 2)
        {
            // cout << i << " ";
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}