#include <bits/stdc++.h>
using namespace std;
int n, ans, f[10005];
// 1 2 3 4 5
// 1 2 3 5 
void fun(int n, int m)
{
    if (n == 0)
    {
        if (!f[m]) ans++, f[m] = 1;
    }
    else
    {
        for (int r = n; r >= 1; r--)
            fun(n - r, r * (n - r) + m);
    }
}
int main()
{
    cin >> n;
    fun(n, 0);
    cout << ans << endl;
    return 0;
}