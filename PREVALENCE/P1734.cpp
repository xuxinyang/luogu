#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int s, a[maxn], f[maxn]; // f[i][j]表示选i个数和为j的最大值
int getps(int x)
{
    int sum = 1;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0) sum += i + x / i;
        if (i * i == x) sum -= i;
    }
    return sum;
}
int main()
{
    cin >> s;
    for (int i = 2; i <= s; i++) a[i] = getps(i);
    for (int i = 1; i <= s; i++)
    {
        for (int j = s; j >= i; j--)
        {
            f[j] = max(f[j], f[j-i]+a[i]);
        }
    }
    cout << f[s];
    return 0;
}