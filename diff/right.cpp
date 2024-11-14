#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, f[1001][1001], ans[1001][1001], cz[1001][1001], a[1001][1001], minn = 1000000009;

void dfs(int lie)
{
    if (lie > m)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cz[i][j] = a[i][j]; // 定义一个操作数组来保存a数组；
        for (int i = 1; i <= m; i++)
            if (f[1][i]) // 已知第一行的修改方案，进行题目要求修改。
            {
                cz[1][i] ^= 1, cz[2][i] ^= 1;
                cz[1][i + 1] ^= 1, cz[1][i - 1] ^= 1;
            }
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (cz[i - 1][j] == 1)
                {
                    f[i][j] = 1;
                    cz[i][j] ^= 1;
                    cz[i][j + 1] ^= 1, cz[i][j - 1] ^= 1;
                    cz[i + 1][j] ^= 1, cz[i - 1][j] ^= 1; // 若第i行为1，则修改i+1行，并按照题目要求修改旁边各点。
                }
                else
                    f[i][j] = 0;
                if (cz[i - 1][j])
                    return;
            }
        bool pd = false;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (cz[i][j]) // 修改完后，依然存在1，肯定impossible；
                {
                    pd = true;
                    break;
                }
        if (!pd)
        {
            int sum = 0;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    if (f[i][j])
                        sum++;
            if (sum >= minn)
                return;
            minn = sum;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    ans[i][j] = f[i][j];
        }
        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        f[1][lie] = i;
        dfs(lie + 1); // dfs第一行的修改方案
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    dfs(1);
    if (minn == 1000000009)
        cout << "IMPOSSIBLE"; // 最小值没有改变，即不可能
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
}