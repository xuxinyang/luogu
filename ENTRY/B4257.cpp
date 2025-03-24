#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    if (x*n <= y) cout << "0\n";
    else
    {
        if (y%x == 0) cout << n-y/x << endl;
        else cout << n-y/x-1 << endl;
    }
    return 0;
}