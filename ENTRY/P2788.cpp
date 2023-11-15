#include <bits/stdc++.h>
using namespace std;
int ans, x;
char op;
int main()
{
    cin >> ans;
    while (cin >> op >> x)
    {
        if (op == '-') ans -= x;
        else ans += x;
    }
    cout << ans;
    return 0;
}