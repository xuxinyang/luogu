#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        int s = 0;
        while (x)
        {
            s += x%10;
            x /= 10;
        }
        if (s % 7 == 0) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}