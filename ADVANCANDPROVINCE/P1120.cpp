#include <bits/stdc++.h>
using namespace std;
const int maxn = 70;
int n, len, cnt, sum, a[maxn];
bool used[maxn];
void dfs(int u, int cur, int start)
{
    if (u > cnt)    // 全部拼好了
    {
        printf("%d", len);
        exit(0);
    }
    if (cur == len) // 拼好了第u根，再拼下一根
    {
        dfs(u+1, 0, 1);
        return;
    }
    for (int i = start; i <= n; i++)
    {
        if (used[i] || cur + a[i] > len) continue;  // 不合法的就跳过
        used[i] = 1;
        dfs(u, cur + a[i], i + 1);
        used[i] = 0;    // 拼接失败，恢复现场
        if (cur == 0) return;   // 拼接第一个，失败回溯
        if (cur + a[i] == len) return;  // 拼接最后一个，失败回溯
        while (i < n && a[i] == a[i+1]) i++; // 跳过与a[i]等长的木棍
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    for (len = a[1]; ; len++)
    {
        if (sum % len) continue;
        cnt = sum / len;
        dfs(1, 0, 1);
    }
    return 0;
}