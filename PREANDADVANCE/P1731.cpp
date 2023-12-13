#include <bits/stdc++.h>
using namespace std;
const int maxm = 20;
const int inf = 1e9;
int n, m, ans = inf;
int minv[maxm], mins[maxm];
// 当前层是第u层，第u+1层的半径为R，高度为H
// m~u+1层的体积和为v，面积和为s
void dfs(int u, int R, int H, int v, int s)
{
    if (u == 0)
    {
        if (v == n) ans = min(ans, s);  // 边界
        return;
    }
    if (v + minv[u] > n) return;    // 体积和越界
    if (s + mins[u] >= ans) return; // 面积和更差
    if (s + 2 * (n-v)/R >= ans) return; // 估价不等式
    for (int r = min(R-1, (int)sqrt(n-v)); r >= u; r--)
    {
        for (int h = min(H-1, (n-v)/(r*r)); h >= u; h--)
        {
            dfs(u-1, r, h, v+r*r*h, s+2*r*h+(u==m?r*r:0));
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        minv[i] = minv[i-1] + i * i * i;    // 最小体积和
        mins[i] = mins[i-1] + 2 * i * i;    // 最小侧面积和
    }
    dfs(m, inf, inf, 0, 0);
    if (ans == inf) ans = -1;
    cout << ans;
    return 0;
}