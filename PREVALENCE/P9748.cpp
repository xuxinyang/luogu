#include <bits/stdc++.h>
using namespace std;
int n, days, times, flag = 0;
int main()
{
    cin >> n;
    while (n)
    {
        days++;
        if (n % 3 == 1 && !flag)
        {
            times = days;
            flag = 1;
        }
        n = n * 2 / 3;
    } 
    cout << days << " " << times;
    return 0;
}