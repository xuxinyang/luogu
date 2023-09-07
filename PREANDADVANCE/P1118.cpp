#include <bits/stdc++.h>
using namespace std;
int n, a[15], s, yh[15][15];
bool vis[15], flag;
void init()
{
    // 杨辉三角初始化
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1 || j == i) yh[i][j] = 1;
            else yh[i][j] = yh[i-1][j] + yh[i-1][j-1];
        }
    }
}
void dfs(int idx)
{
    if (flag) return;
    int sum = 0;
    for (int i = 1; i < idx; i++)
    {
        sum += a[i] * yh[n][i];
    }
    if (sum > s) return;
    if (idx == n+1)
    {
        if (sum == s) flag = 1;
        if (flag)
        {
            for (int i = 1; i <= n; i++) cout << a[i] << " ";
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            a[idx] = i;
            vis[i] = 1;
            dfs(idx + 1);
            a[idx] = vis[i] = 0;
        }
    }
}
int main()
{
    cin >> n >> s;
    init();
    dfs(1);
    return 0;
}