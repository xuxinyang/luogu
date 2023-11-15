#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, cnt5 = 0, cnt0 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x == 0) cnt0++;
        else cnt5++;
    }
    cnt5 = cnt5/9*9;
    if (cnt0 == 0) cout << -1;
    else
    {
        for (int i = 1; i <= cnt5; i++) cout << 5;
        if (cnt5 == 0) cout << 0;
        else
            for (int i = 1; i <= cnt0; i++) cout << 0;
    }
    return 0;
}