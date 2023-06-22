#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+5;
int n, a[maxn], b[maxn], c[maxn], len;
int main()
{
    cin >> n;
    a[1] = 1, b[1] = 2;
    len = 1;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    if (n == 2)
    {
        cout << 2;
        return 0;
    }
    for (int i = 3; i <= n; i++)
    {
        // c = a + b;
        memset(c, 0, sizeof(c));
        for (int j = 1; j <= len; j++)
        {
            c[j] += a[j] + b[j];
            c[j+1] += c[j] / 10;
            c[j] = c[j] % 10; 
        }
        if (c[len+1] > 0) len++;
        for (int j = 1; j <= len; j++) a[j] = b[j];
        for (int j = 1; j <= len; j++) b[j] = c[j];
    }
    while (c[len]==0 && len > 1) len--;
    for (int i = len; i >= 1; i--) cout << c[i];
    return 0;
}