#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0) return false;
    }
    return true;
}
bool isLeap(int y)
{
    return y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    return 0;
}