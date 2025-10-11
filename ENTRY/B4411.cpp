#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x = i, last = i%10, f = 1;
        while (x)
        {
            if (x%10 != last) f = 0;
            x /= 10;
        }
        if (f) cnt++;
    }
    cout << cnt;
    return 0;
}