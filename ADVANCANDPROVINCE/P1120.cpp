#include <bits/stdc++.h>
using namespace std;

int num[500010], maxn, minn, sum;

int max(int x, int y)
{
    return x > y ? x : y;
}

int min(int x, int y)
{
    return x > y ? y : x;
}
void dfs(int wait, int already, int need, int can)
{ 
    int i;
    if (wait == 0)
    { 
        printf("%d", need); 
        exit(0);
    }
    if (already == need)
    {
        dfs(wait - 1, 0, need, maxn);
        return;
    }
    for (i = can; i >= minn; i--)
        if (num[i] && i + already <= need)
        {
            num[i]--;
            dfs(wait, already + i, need, i);
            num[i]++;
            if (already == 0 || already + i == need)
                return;
        }
}

int main()
{
    int i, j, k, m, n, temp;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        if (k <= 50)
        {
            sum += k;
            num[k]++;
            minn = min(k, minn);
            maxn = max(k, maxn);
        }
    }
    temp = sum / 2;
    for (i = maxn; i <= temp; i++)
        if (sum % i == 0)
            dfs(sum / i, 0, i, maxn);
    printf("%d", sum);
    return 0;
}