#include <bits/stdc++.h>
using namespace std;
int a[1005], x, n, cnt;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[x] = 1;
    }
    for (int i = 1; i <= 1000; i++)
    {
        if (a[i] != 0) cnt++;
    }
    cout << cnt << "\n";
    for (int i = 1; i <= 1000; i++)
    {
        if (a[i] != 0) cout << i << " ";
    }
    return 0;
}