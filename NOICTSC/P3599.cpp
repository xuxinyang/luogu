#include <bits/stdc++.h>
using namespace std;
#define lng long long
#define lit long double
#define re register
#define kk(i, n) " \n"[i == n]
const int inf = 0x3f3f3f3f;
const lng Inf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5;
int X, T, n;
void solve1()
{
    if ((n & 1) && (n ^ 1))
        return puts("0"), void();
    else
    {
        putchar('2'), putchar(' ');
        for (int i = 1; i <= n; i++)
            printf("%d%c", (i & 1) ? n + 1 - i : i - 1, kk(i, n));
    }
}
bitset<N + 10> np;
int p[N + 10], cnt;
void Prime()
{
    np[1] = true;
    for (int i = 1; i <= N; i++)
    {
        if (!np[i])
            p[++cnt] = i;
        for (int j = 1; j <= cnt && i * p[j] <= N; j++)
            np[i * p[j]] = 1;
    }
}
int Pow(int a, int x)
{
    int res = 1;
    for (; x; a = 1ll * a * a % n, x >>= 1)
        if (x & 1)
            res = 1ll * res * a % n;
    return res;
}
void solve2()
{
    if (np[n] && (n ^ 1) && (n ^ 4))
        return puts("0"), void();
    else
    {
        if (n == 1)
            return puts("2 1"), void();
        if (n == 4)
            return puts("2 1 3 2 4"), void();
        putchar('2');
        for (int i = 1, tmp = 1, sum = 1; i <= n - 1; i++)
        {
            printf(" %d", tmp);
            tmp = 1ll * Pow(sum, n - 2) * (i + 1) % n;
            sum = 1ll * sum * tmp % n;
        }
        printf(" %d", n), putchar('\n');
    }
}

int main()
{
    scanf("%d%d", &X, &T);
    if (X == 2)
        Prime();
    for (int ti = 1; ti <= T; ti++)
    {
        scanf("%d", &n);
        if (X == 1)
            solve1();
        else
            solve2();
    }
    return 0;
}