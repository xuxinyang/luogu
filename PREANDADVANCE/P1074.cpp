#include <bits/stdc++.h>
using namespace std;
const int w[9][9] = {
    {6, 6, 6, 6, 6, 6, 6, 6, 6},
    {6, 7, 7, 7, 7, 7, 7, 7, 6},
    {6, 7, 8, 8, 8, 8, 8, 7, 6},
    {6, 7, 8, 9, 9, 9, 8, 7, 6},
    {6, 7, 8, 9,10, 9, 8, 7, 6},
    {6, 7, 8, 9, 9, 9, 8, 7, 6},
    {6, 7, 8, 8, 8, 8, 8, 7, 6},
    {6, 7, 7, 7, 7, 7, 7, 7, 6},
    {6, 6, 6, 6, 6, 6, 6, 6, 6}};
int a[9][9], ans = -1, x, p, cnt[10][10], c;
struct HL
{
    int val, k;
};
HL hl[100];
bool row[10][10], col[10][10], g[10][10];
void dfs(int idx)
{
    if (idx > 80)
    {
        int res = 0;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                res += a[i][j] * w[i][j];
            }
        }
        ans = max(ans, res);
        return;
    }
    int fx = hl[idx].k / 9, fy = hl[idx].k % 9;
    if (a[fx][fy])
        dfs(idx + 1);
    else
    {
        for (int val = 1; val <= 9; val++)
        {
            if (!row[fx][val] && !col[fy][val] && !g[fx/3*3+fy/3][val])
            {
                row[fx][val] = col[fy][val] = g[fx/3*3+fy/3][val] = 1;
                a[fx][fy] = val;
                dfs(idx+1);
                a[fx][fy] = 0;
                row[fx][val] = col[fy][val] = g[fx/3*3+fy/3][val] = 0;
            }
        }
    }
}
int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> a[i][j];
            x = a[i][j];
            row[i][x] = col[j][x] = g[i / 3 * 3 + j / 3][x] = 1;

        }
    }
    // 统计每一行0的个数
    for (int i = 0; i < 9; i++)
    {
        int t = 0;
        for (int j = 0; j < 9; j++)
        {
            if (a[i][j]) t++;
        }
        cnt[i][9] = t;
    }
    // 统计每一列0的个数
    for (int i = 0; i < 9; i++)
    {
        int t = 0;
        for (int j = 0; j < 9; j++)
        {
            if (a[j][i]) t++;
        }
        cnt[9][i] = t;
    }
    // 每一行每一列0的个数
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cnt[i][j] = cnt[i][9] + cnt[9][j];
            hl[p++] = HL{cnt[i][j], i * 9 + j};
        }
    }
    sort(hl, hl + p, [](HL x, HL y){
        if (x.val == y.val)
        {
            if (x.k/9 == y.k/9) return x.k%9 < y.k%9;
            else return x.k/9 < y.k/9;
        }
        return x.val > y.val;
    });
    dfs(0);
    cout << ans;
    return 0;
}