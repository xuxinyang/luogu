#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
const int maxp = 500;
int a[maxn], c[maxn], n;
void mul(int a[], int b[])
{
    int tmp[maxn];
    memset(tmp, 0, sizeof(tmp));
    for (int i = 1; i <= maxp; i++)
    {
        for (int j = 1; j <= maxp; j++)
            tmp[i+j-1] += a[i] * b[j];
    }
    for (int i = 1; i <= maxp; i++) tmp[i+1] += tmp[i]/10, tmp[i] %= 10;
    for (int i = 1; i <= maxp; i++) a[i] = tmp[i];
}
void qpow(int p)
{
    while (p)
    {
        if (p & 1) mul(c, a);
        p >>= 1;
        mul(a, a);
    }
}
int main()
{
    cin >> n;
    cout << int(log10(2)*n) + 1 << "\n";
    a[1] = 2, c[1] = 1;
    qpow(n);
    c[1]-=1;
    for (int i = 500; i >= 1; i--)
    {
        if (i != 500 && i % 50 == 0) cout << "\n";
        cout << c[i];
    }
    return 0;
}