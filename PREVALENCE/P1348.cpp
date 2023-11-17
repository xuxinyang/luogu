#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, ans = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (i&1 || i%4==0) ans++;
    }
    cout << ans;
    return 0;
}