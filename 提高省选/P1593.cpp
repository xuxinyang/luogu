#include <bits/stdc++.h>
using namespace std;
#define mod 9901
int a, b, sa, f[10005][2], cnt, ans = 1;
int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (res % mod) * (a % mod) % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

int sum(int x, int y)
{
    int k = 0;
    y = y * b;
    if (x % mod == 1)
    {
        k = (y + 1) % mod;
    }
    else
    {
        k = (qpow(x % mod, y + 1) - 1) % mod * qpow((x-1)%mod, mod-2) % mod;
    }
    return k % mod;
}

int main()
{
    cin >> a >> b;
    if (a == 0)
    {
        printf("0\n");
        return 0;
    }
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            cnt++;
            f[cnt][0] = i;
            f[cnt][1] = 1;
            a /= i;
            while (a % i == 0)
            {
                f[cnt][1]++;
                a /= i;
            }
        }
    }
    if (a != 1)
    {
        cnt++;
        f[cnt][0] = a;
        f[cnt][1] = 1;
    }
    for (int i = 1; i <= cnt; i++)
        ans = ans * sum(f[i][0], f[i][1]) % mod;
    printf("%d\n", (ans % mod + mod) % mod);
    return 0;
}