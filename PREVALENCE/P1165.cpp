#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int n, a[maxn], op, x, p;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    while (n--)
    {
        cin >> op;
        if (op == 0)
        {
            cin >> x;
            a[++p] = max(x, a[p]);
        }
        else if (op == 1) p--;
        else 
        {
            cout << a[p] << "\n";
        }
    }
    return 0;
}