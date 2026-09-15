#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    n = 2*n-1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i+j==n/2+2 || i+j==n+n/2+1 || i-j==n/2 || j-i==n/2)
            {
                cout << '+';
            }
            else cout << '.';
        }
        cout << "\n";
    }
    return 0;
}