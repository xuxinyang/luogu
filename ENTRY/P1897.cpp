#include <cstdio>
int n, a, ans, max;
bool s[100000000];
int main(void)
{
    s[0] = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (!s[a])
            ans += 5;
        s[a] = 1;
        if (a > max)
            max = a;
    }
    ans += n;
    ans += max * 10;
    printf("%d", ans);
}