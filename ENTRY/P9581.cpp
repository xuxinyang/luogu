#include <bits/stdc++.h>
using namespace std;
int a, b, ans;
int main()
{
    cin >> a >> b;
    if (a == b) cout << abs(a);
    else if (a < b)
    {
        if (a >= 0) cout << b;
        else cout << b - a + min(abs(a), abs(b));
    }
    else
    {
        if (b >= 0) cout << a;
        else cout << a - b + min(abs(a), abs(b));
    }
    return 0;
}