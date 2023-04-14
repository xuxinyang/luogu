#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, a[10];
    for (int i = 0; i <= 9; i++) a[i] = 0;
    cin >> m >> n;
    for (int i = m; i <= n; i++)
    {
        int tmp = i;
        while (tmp)
        {
            a[tmp % 10] ++ ;
            tmp /= 10;
        }
    }
    for (int i = 0; i <= 9; i++) cout << a[i] << " ";
    return 0;
}