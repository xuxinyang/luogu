#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, a[maxn], b[maxn], len;
int main()
{
    cin >> n;
    a[1] = b[1] = 1;
    len = 1;
    for (int i = 2; i <= n; i++)
    {
        // 高精度阶乘
        int carry = 0;
        for (int j = 1; j <= len; j++)
        {
            a[j] = a[j] * i + carry;
            carry = a[j] / 10;
            a[j] = a[j] % 10;
            if (carry > 0 && j >= len) len++;
        }
        // 阶乘之和
        for (int j = 1; j <= len; j++)
        {
            b[j] += a[j];
            b[j+1] += b[j] / 10;
            b[j] = b[j] % 10;
        }
    }
    while (b[len]==0 && len > 1) len--;
    for (int i = len; i >= 1; i--) cout << b[i];
    return 0;
}