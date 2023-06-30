#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int n, m, len = 1;
int a[maxn], b[maxn], c[maxn];
int main()
{
    cin >> m >> n;
    a[1] = 1;
    b[1] = 2;
    for (int i = 3; i <= n-m; i++)
    {
        memset(c, 0, sizeof(c));
        for (int j = 1; j <= len; j++)
        {
            c[j] += a[j] + b[j];
            c[j+1] += c[j] / 10;
            c[j] = c[j] % 10;
        }
        if (c[len+1] > 0) len++;
        for (int j = 1; j <= len; j++) 
            a[j] = b[j], b[j] = c[j];
    }
    for (int i = len; i >= 1; i--) cout << c[i];
    return 0;
}