#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 70;
int n, a[N], cnt, maxn, maxnn;
bool cmp(int x, int y) { return x > y; }
bool use[N];
inline void dfs(int ans, int sum, int goal, int now)
{
    if (sum * goal == maxn)
    {
        printf("%d\n", goal);
        exit(0);
    }
    if (ans == goal)
    {
        dfs(0, sum + 1, goal, 1);
        return;
    } 
    if (goal - ans < a[cnt])
        return;
    for (register int i = now; i <= cnt; i++)
        if (!use[i] && ans + a[i] <= goal)
        {
            use[i] = 1;
            dfs(ans + a[i], sum, goal, i + 1);
            use[i] = 0;
            if (ans + a[i] == goal || ans == 0)
                break;
            while (a[i] == a[i + 1])
                i++;
        }
}
int main()
{
    scanf("%d", &n);
    for (register int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x <= 50)
        {
            a[++cnt] = x;
            maxn += a[cnt];
            maxnn = max(a[cnt], maxnn);
        }
    }
    sort(a + 1, a + cnt + 1, cmp);
    for (register int i = maxnn; i <= maxn / 2; i++) 
        if (maxn % i == 0)
            dfs(0, 0, i, 1);
    printf("%d\n", maxn);
    return 0;
}