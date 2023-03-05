#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, ans;
    cin >> n >> m;
    if (m == 1)
    {
        cout << n << endl;
        return 0;
    }
    for (int i = 1;pow(i, m)<=n; i++) ans++;
    cout << ans << endl;
    return 0;
}