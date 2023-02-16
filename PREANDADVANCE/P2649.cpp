#include <bits/stdc++.h>
using namespace std;

int n, m, ans, res;
int a[55];
bool b[1005];
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]] = true;
    }
    for (int i = n * m; i >= 1; i--)
    {
        if (!b[i]) ans++;
        else if (ans > 0) ans--;
        else res++;
    }
    cout << res << endl;
    return 0;
}