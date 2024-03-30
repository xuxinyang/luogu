#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, m, x, y;
int first[maxn], last[maxn], dx[maxn<<1], nxt[maxn<<1], xb;
long long dp[1<<20][20], cnt;
void build(int x, int y)
{
    dx[++xb] = y;
    if (!first[x]) first[x] = xb;
    else nxt[last[x]] = xb;
    last[x] = xb;
} 
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        x--, y--;
        build(x, y), build(y, x);
    }
    for (int i = 0; i < n; i++) dp[1<<i][i] = 1;
    for (int k = 1; k < (1 << n); k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (!dp[k][i]) continue;
            for (int j = first[i]; j; j = nxt[j])
            {
                int y = dx[i];
                if ((k & (-k)) > (1 << y)) continue;
                if (k & (1 << y))
                {
                    if ((k & (-k)) == (1 << y)) cnt += dp[k][i];
                }
                else dp[k|(1<<y)][y] += dp[k][i];
            }
        }
    }
    printf("%lld\n", (cnt-m)/2);
    return 0;
}