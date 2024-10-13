#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, k;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if (k == 0)
        {
            cout << 1 << "\n";
            continue;
        }
        ll qmax = n/k;
        ll qmin = n/(k+1);
        cout << qmax-qmin << "\n";
    }
    return 0;
}