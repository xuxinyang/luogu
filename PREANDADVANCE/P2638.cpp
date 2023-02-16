#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define ull unsigned long long
ull n, a, b;
struct Num
{
    ull l, a[30];
} ans, dp[55][55][55];
Num operator+(Num x, Num y)
{
    Num ret;
    ret.l = max(x.l, y.l);
    memset(ret.a, 0, sizeof(ret.a));
    // 一定要清零！！！
    for (int i = 1; i <= ret.l; i++)
    {
        ret.a[i] += x.a[i] + y.a[i];
        ret.a[i + 1] += ret.a[i] / 10;
        ret.a[i] %= 10;
    }
    if (ret.a[ret.l + 1])
        ret.l++;
    return ret;
}
void print(Num x)
{
    if (x.l == 1 && x.a[1] == 0)
    {
        cout << 1 << endl;
        return;
    }
    for (int i = x.l; i >= 1; i--)
        printf("%lld", x.a[i]);
    printf("\n");
}
int main()
{
    scanf("%lld%lld%lld", &n, &a, &b);
    dp[0][0][0].l = dp[0][0][0].a[1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= a; j++)
            for (int k = 0; k <= b; k++)
                for (int s1 = 0; s1 <= j; s1++)
                    for (int s2 = 0; s2 <= k; s2++)
                        dp[i][j][k] = dp[i][j][k] + dp[i - 1][s1][s2];
    for (int i = 0; i <= a; i++)
        for (int j = 0; j <= b; j++)
            ans = ans + dp[n][i][j];
    print(ans);
    return 0;
}