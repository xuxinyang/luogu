#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int dp[N][N];
char c[N];
int main()
{
    cin >> c+1;
    int n = strlen(c+1);
    for (int len = 1; len <= n; len++)  // 外循环枚举串长度
    {
        for (int i = 1; i + len - 1 <= n; i++)   // 枚举起点（左端点）
        {
            int j = i+len-1;  // 计算出右端点
            if (c[i] == c[j]) dp[i][j] = dp[i+1][j-1];  // 回文不动
            else dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + 1;    // 否则在上一段里取最小值，补充字符更新
        }
    }
    cout << dp[1][n];
    return 0;
}