#include <bits/stdc++.h>
using namespace std;
int m, n, t;
int f(int m, int n)
{
    if (m == 0 || m == 1 || n == 1) return 1;
    if (m < n) return f(m, m);
    return f(m, n-1) + f(m-n, n);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        cout << f(m, n) << "\n";
    }
    return 0;
}