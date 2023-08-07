#include <bits/stdc++.h>
using namespace std;
int n;
int a[105], b[105], len;
int main()
{
    cin >> n;
    a[1] = 2, len = 1;
    for (int i = 2; i <= n; i++)
    {
        // b = 2 * a + 2;
        b[1] += 2;
        for (int j = 1; j <= len; j++)
        {
            b[j] += a[j] + a[j];
            b[j+1] += b[j] / 10;
            b[j] %= 10;
        }
        if (b[len+1] > 0) len++;
        // a = b;
        for (int j = 1; j <= len; j++) a[j] = b[j], b[j] = 0;
    }
    // 去前导0
    while (a[len] == 0 && len > 1) len--;
    for (int i = len; i >= 1; i--) cout << a[i];
    return 0;
}