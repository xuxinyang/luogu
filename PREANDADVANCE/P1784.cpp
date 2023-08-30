#include <bits/stdc++.h>
using namespace std;
int a[10][10], x;
bool row[10][10], col[10][10], g[10][10], flag;
void dfs(int k)
{
    if (flag) return;
    if (k > 80)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        flag = 1;
        return;
    }
    int fx = k / 9;
    int fy = k % 9;
    if (a[fx][fy]) dfs(k+1);
    else
    {
        for (int val = 1; val <= 9; val++)
        {
            if (!row[fx][val] && !col[fy][val] && !g[fx/3*3+fy/3][val])
            {
                row[fx][val] = col[fy][val] = g[fx/3*3+fy/3][val] = 1;
                a[fx][fy] = val;
                dfs(k+1);
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
            row[i][x] = col[j][x] = g[i/3*3+j/3][x] = 1;
        }
    }
    dfs(0);
    return 0;
}