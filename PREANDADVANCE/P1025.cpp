#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
/**
 * @brief 用来求解能划分为多少个数
 * 
 * @param cnt 选了cnt个数
 * @param sum 当前所选的数的和为sum
 * @param start 保证所选数据不重复
 */
void dfs(int start, int sum, int cnt)
{
    if (cnt == k)
    {
        if (sum == n) ans++;
        return;
    }
    for (int i = start; sum + i * (k - cnt) <= n; i++)
    {
        dfs(i, sum + i, cnt + 1);
    }
}
int main()
{
    cin >> n >> k;
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}