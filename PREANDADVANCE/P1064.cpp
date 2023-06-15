#include <bits/stdc++.h>
using namespace std;

int N, m, w[200], c[200], x, dp[200][40000]; // 数组大小qwq
int head[200], k = 1;                        // 链式前向星加边用
struct edge
{
    int to, next;
} e[200]; // 树的边

void adde(int u, int v) // 链式前向星加边
{
    e[k].to = v;
    e[k].next = head[u];
    head[u] = k++;
}

void dfs(int u, int t, int fa)
// u是当前节点，t是当前容量，fa是父亲节点
{
    if (t <= 0)
        return;                             // 装不下了
    for (int i = head[u]; i; i = e[i].next) // 访问与该点相连的每一条边
    {
        int v = e[i].to;
        if (v == fa)
            continue; // 如果是父节点则跳过
        for (int k = N - w[v]; k >= 0; k--)
            dp[v][k] = dp[u][k] + c[v]; // 要选子树，就必须选该节点
        dfs(v, t - w[v], u);            // 继续递归
        for (int k = N; k >= w[v]; k--)
            dp[u][k] = max(dp[u][k], dp[v][k - w[v]]); // 选或不选（这是01背包）
    }
}

int main()
{
    scanf("%d%d", &N, &m);
    for (register int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &w[i], &c[i], &x);
        c[i] *= w[i]; // 读入
        adde(i, x);
        adde(x, i); // 连双向边
    }
    dfs(0, N, -1); // 0为虚拟根节点，深搜跑dp
    int ans = 0;
    for (register int i = 0; i <= N; i++)
        ans = max(ans, dp[0][i]);
    printf("%d\n", ans); 
    return 0;
}