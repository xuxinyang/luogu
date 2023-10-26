#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int R, C, A, B, mp[maxn][maxn], sum[maxn][maxn];
int ans, l, r, mid;
bool check(int x)
{
    int idx = 0, row_cnt = 0;
    for (int i = 1; i <= R; i++)
    {
        int col_sum = 0, col_cnt = 0;
        for (int j = 1; j <= C; j++)
        {
            if (col_sum + (sum[i][j]-sum[i][j-1]) - (sum[idx][j]-sum[idx][j-1]) < x)
            {
                col_sum += (sum[i][j]-sum[i][j-1]) - (sum[idx][j]-sum[idx][j-1]);
            } 
            else
            {
                col_cnt++;
                col_sum = 0;
            }
        }
        if (col_cnt >= B) idx = i, row_cnt++;
    }
    return row_cnt >= A;
}
int main()
{
    cin >> R >> C >> A >> B;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> mp[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] + mp[i][j] - sum[i-1][j-1];
        }
    }
    l = 0, r = sum[R][C];
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}