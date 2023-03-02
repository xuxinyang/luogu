#include <bits/stdc++.h>
using namespace std;
int n, f[105], a, b, ans;
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> f[i];
    }
    cin >> a >> b;
    for (int i = a; i < b; i++)
    {
        ans += f[i];
    }
    cout << ans << endl;
    return 0;
}