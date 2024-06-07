#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n&1) cout << (n+1)*(2*n*n+3*n-1)/8 << "\n";
        else cout << n*(n+2)*(2*n+1)/8 << "\n";
    }
    return 0;
}