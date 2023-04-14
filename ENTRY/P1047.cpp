#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
int main()
{
    int a[maxn],l, m, u, v, cnt = 0;
    cin >> l >> m;
    // 1. 将0-l下标对应的值全部初始化为1
    for (int i = 0; i <= l; i++) a[i] = 1;
    // 2. 将m个区域的树都挪走
    // 2.1 外循环重复执行m次
    for (int i = 1; i <= m; i++)
    {
        // 2.2 输入每次区域的开始和结束位置
        cin >> u >> v;
        // 2.3 遍历这个区域的每一个树，都置为0，代表删除了这棵树
        for (int j = u; j <= v; j++)
        {
            a[j] = 0;
        }
    }
    // 3. 统计标记位还为1的树的个数，就是没被移走的
    for (int i = 0; i <= l; i++)
    {
        if (a[i] == 1) cnt++;
    }
    cout << cnt << endl;
    return 0;
}