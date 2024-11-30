#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n, m, r, c, minx, minc;
int num[20][20], ch[20], idx=1;
int col[20], row[20][20], f[20][20];
void init()
{
    for (int i = 1; i <= m; i++)
    {
        col[i] = 0;
        for (int j = 1; j < r; j++)
            col[i] += abs(num[ch[j]][i]-num[ch[j+1]][i]);
    }
    for (int i = 2; i <= m; i++)
    {
        for (int j = 1; j < i; j++)
        {
            row[i][j] = 0;
            for (int k = 1; k <= r; k++)
                row[i][j] += abs(num[ch[k]][i] - num[ch[k]][j]);
        }
    }
}
void process()
{
    for (int i = 1; i <= m; i++)
    {
        minc = min(i, c);
        for (int j = 1; j <= minc; j++)
        {
            if (j == 1) f[i][j] = col[i];
            else if (i == j) f[i][j] = f[i-1][j-1] + col[i] + row[i][j-1];
            else
            {
                f[i][j] = inf;
                for (int k = j-1; k < i; k++) 
                    f[i][j] = min(f[i][j], f[k][j-1]+col[i]+row[i][k]);
            }
            if (j == c) minx = min(minx, f[i][c]);
        }
    }
}
void dfs(int k)
{
    if (k > n) 
    {
        init(), process();
        return;
    }
    if (r-idx+1 == n-k+1)
    {
        ch[idx++] = k, dfs(k+1), ch[idx--] = 0;
        return;
    }
    dfs(k + 1);
    if (idx <= r)
    {
        ch[idx++] = k;
        dfs(k+1);
        ch[idx--] = 0;
    }
}
int main()
{
    cin >> n >> m >> r >> c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cin >> num[i][j];
    }
    minx = inf;
    dfs(1);
    cout << minx;
    return 0;
}