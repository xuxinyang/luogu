#include <bits/stdc++.h>
using namespace std;

constexpr int N = 205;

int a[N * N], b[N * N], c[N * N];

int main()
{
    int n;
    cin >> n;
    a[0] = 1;
    b[0] = 0;
    int len = 1;
    if (n == 0)
    {
        cout << 1;
        return 0;
    }
    for (int i = 2; i <= n; i++)
    {
        memset(c, 0, sizeof c);
        // D(i) = (i - 1) * (D(i - 1) + D(i - 2))
        int carry = 0;
        for (int j = 0; j < len; j++)
        {
            int x = (a[j] + b[j]) * (i - 1) + carry;
            c[j] = x % 10;
            carry = x / 10;
        }
        while (carry > 0)
        {
            c[len++] = carry % 10;
            carry /= 10;
        }
        for (int j = 0; j < len; j++)
        {
            a[j] = b[j];
            b[j] = c[j];
        }
    }
    for (int i = len - 1; i >= 0; i--) cout << b[i];
    return 0;
}