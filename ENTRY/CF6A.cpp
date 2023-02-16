#include <bits/stdc++.h>
using namespace std;
int a[4];
int main()
{
    for (int i = 1; i <= 4; i++) cin >> a[i];
    sort(a + 1, a + 4 + 1);
    if (a[1] + a[2] > a[3] || a[2] + a[3] > a[4])
    {
        cout << "TRIANGLE";
    }
    else if (a[1] + a[2] == a[3] || a[2] + a[3] == a[4])
    {
        cout << "SEGMENT";
    }
    else cout << "IMPOSSIBLE";
    return 0;
}