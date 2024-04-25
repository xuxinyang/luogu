#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e7;
char a[maxn], s[maxn];
int d[maxn];    // 回文半径
void get_d(char *s, int n)
{
    d[1] = 1;
    for (int i = 2, l, r=1; i <= n; i++)
    {
        if (i <= r) d[i] = min(d[r-i+l], r-i+1);
        while (s[i-d[i]] == s[i+d[i]]) d[i]++;
        if (i+d[i]-1>r) l = i-d[i]+1, r = i+d[i]-1;
    }
}
int main()
{
    scanf("%s", a+1);
    int n = strlen(a+1), k = 0;
    s[0] = '$', s[++k] = '#';
    for (int i = 1; i <= n; i++) s[++k] = a[i], s[++k] = '#';
    n = k;
    get_d(s, n); // 计算d函数
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, d[i]);
    printf("%d\n", ans-1);
    return 0;
}