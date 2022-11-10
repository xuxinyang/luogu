#include <bits/stdc++.h>
#define ll long long
using namespace std;
// 马可以到达的点，包括自身总共9个点，有些点可能越界走不到
const int fx[9] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int fy[9] = {0, 1, 2, 2, 1, -1, -2, -2, -1};

int bx, by, mx, my;
ll f[25][25];
bool h[25][25]; // 标记马能走到的点
int main()
{
    cin >> bx >> by >> mx >> my;
    bx += 2, by += 2;   // 做偏移，以至于后面不用判断马是否在数组边界内
    mx += 2, my += 2;   // 马的坐标也做偏移
    f[2][1] = 1;
    h[mx][my] = 1; 
    for (int i = 0; i <= 8; i++)
        h[mx+fx[i]][my+fy[i]] = 1;
    for (int i = 2; i <= bx; i++)
    {
        for (int j = 2; j <= by; j++)
        {
            if (h[i][j]) continue; // 如果被马拦住就直接跳过
            f[i][j] = f[i - 1][j] + f[i][j - 1]; // 递推方程
        }
    }
    cout << f[bx][by] << endl;
    return 0;
}