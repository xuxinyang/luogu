#include <bits/stdc++.h>
using namespace std;
int a[25][25], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1 || j == i)
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = a[i-1][j-1] + a[i-1][j];
            }
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}