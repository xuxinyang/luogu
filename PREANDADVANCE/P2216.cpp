#include <bits/stdc++.h>
using namespace std;
#define N 1005
int m[N][N], q[N];
int rmin[N][N], rmax[N][N], cmin[N][N], cmax[N][N];
int a, b, n, ans = 1e9;
int main()
{
    cin >> a >> b >> n;
    for (int i = 1; i <= a; i++) for (int j = 1; j <= b; j++) cin >> m[i][j];
    for (int r = 1; r <= a; r++)
    {
        // 求解每行区间最大值
        int h = 0, t = 0;
        for (int i = 1; i <= b; i++)
        {
            while (h < t && q[h] + n <= i) h++;
            while (h < t && m[r][q[t-1]] < m[r][i]) t--;
            q[t] = i, t++;
            if (i >= n) rmax[r][i-n+1] = m[r][q[h]];
        }
        // 求每行区间最小值
        h = 0, t = 0;
        for (int i = 1; i <= b; i++)
        {
            while (h < t && q[h]+n <= i) h++;
            while (h < t && m[r][q[t-1]] > m[r][i]) t--;
            q[t] = i, t++;
            if (i >= n) rmin[r][i-n+1] = m[r][q[h]];
        }
    }
    for (int c = 1; c <= b-n+1; c++)
    {
        // 在刚得到的新矩阵的基础上，求每列区间最大值
        int h = 0, t = 0;
        for (int i = 1; i <= a; i++)
        {
            while (h < t && q[h]+n <= i) h++;
            while (h < t && rmax[q[t-1]][c] <= rmax[i][c]) t--;
            q[t] = i, t++;
            if (i >= n) cmax[i-n+1][c] = rmax[q[h]][c];
        }
        // 求每列区间最小值
        h = 0, t = 0;
        for (int i = 1; i <= a; i++)
        {
            while (h < t && q[h] + n <= i) h++;
            while (h < t && rmin[q[t-1]][c] > rmin[i][c]) t--;
            q[t] = i, t++;
            if (i >= n) cmin[i-n+1][c] = rmin[q[h]][c];
        }
    }
    for (int i = 1; i <= a-n+1; i++)
    {
        for (int j = 1; j <= b-n+1; j++)
        {
            if (cmax[i][j]-cmin[i][j] < ans)
                ans = cmax[i][j]-cmin[i][j];
        }
    }
    cout << ans;
    return 0;
}