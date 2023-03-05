#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int a, b;
        for (a = sqrt(n); a >= 1; a--) if (!(n%a)) break;
        b = n/a;
        if ((a+b+2)*2 <= m) cout << "Good\n";
        else cout << "Miss\n"; 
    }
    return 0;
}