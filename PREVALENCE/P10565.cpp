#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if (k ^ 1) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}