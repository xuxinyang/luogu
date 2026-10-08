#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 24;
int g[N], nxt[12][4], fa[N], ans[20], choice[N];

struct node
{
    int state; // 状态
    double F;  // 状态对应估价函数值
    node(int s) : state(s)
    { // 构造函数
        double h = 0;
        F = 0;
        for (int i = 0; i < 12; i++)
            if ((s >> (i * 2)) & 3) // 计算不处在状态1的旋钮的对应的h值
                h += 4 - ((s >> (i * 2)) & 3);
        F = h + g[s]; // 计算估值函数
    }
    bool operator<(const node &y) const
    {
        return F > y.F; // 估价函数值小的优先
    }
};

priority_queue<node> q;

int main()
{
    int button, Start = 0;
    for (int i = 0; i < 12; i++)
    {
        scanf("%d", &button);
        Start |= (button - 1) << (i * 2); // 记录初始状态
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &nxt[i][j]);
            nxt[i][j] -= 1;
        }
    }
    q.push(node(Start)); // 调用构造函数，顺便计算出估价函数值
    g[Start] = 0;

    while (!q.empty())
    {
        int state = q.top().state;
        q.pop();
        if (state == 0)
            break;

        int si, sNxt, nx, nextState;
        for (int i = 0; i < 12; i++)
        {
            si = (state >> (i * 2)) & 3;    // 第 i 个按钮的状态
            nx = nxt[i][si];                // 受牵连的按钮
            sNxt = (state >> (nx * 2)) & 3; // 受牵连的按钮的状态

            nextState = state ^ (si << (i * 2)) ^ (((si + 1) & 3) << (i * 2));
            nextState = nextState ^ (sNxt << (nx * 2)) ^ (((sNxt + 1) & 3) << (nx * 2));

            // 如果没有访问过就可以转移新状态了
            if (!g[nextState])
            {
                g[nextState] = g[state] + 1;
                fa[nextState] = state;     // 记录操作路径
                choice[nextState] = i + 1; // 记录操作按钮
                q.push(node(nextState));
            }
        }
    }

    int cnt = 0, state = 0;
    while (state != Start)
    {
        ans[++cnt] = choice[state];
        state = fa[state];
    }
    printf("%d\n", cnt);
    for (int i = cnt; i; i--)
        printf("%d ", ans[i]);
    return 0;
}
