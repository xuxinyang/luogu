#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int x, r, m, n, p, d[maxn];    // r代表成本价,x代表期望价格，d代表价位
double minx = -1e9, maxx = 1e9; // 答案区间，开始无穷大

inline void read(int &a)
{
    register char c = getchar();
    bool f = 0;
    for (a = 0; c < '0' || '9' < c; c = getchar())
        if (c == '-')
            f = 1; // 要写快读记得判负数，有-1
    for (; '0' <= c && c <= '9'; c = getchar())
        a = (a << 3) + (a << 1) + (c ^ 48);
    if (f)
        a = -a;
}

int main()
{
    read(x);
    read(m);
    read(n);
    r = m; // 记录成本价
    while (m != -1 && n != -1)
    {
        d[m] = n;
        for (int i = p + 1; i < m; i++)
            d[i] = d[i - 1] + (n - d[p]) / (m - p); // 此处递推、未知价格销量，(n-d[p])/(m-p)是公差
        p = m;                                      // 记录上一次的m。
        read(m);
        read(n);
    }
    read(m); // 此时m是最后输入的数
    while (d[p] > m)
        p++, d[p] = d[p - 1] - m;         // 继续递推，递推完成后p就是d>0的范围
    for (register int i = r; i <= p; i++) // 从成本到p的递推
    {
        double ans = (d[x] * (x - r) - d[i] * (i - r)) * 1.0 / (d[i] - d[x]);
        // 求(x+d[i])*(i-r)<=（x+d[x_])+(x_-r)的通解，x_是期望价格
        double g = d[i] - d[x]; // 判断解的符号,g为正是小于，反之为大于。
        if (g > 0)
            maxx = min(maxx, ans); // 取所有"x<=..."中的最小值
        else
            minx = max(minx, ans); // 取所有"x>=..."中的最大值
    }
    // 此时[minx,maxxn]就是答案的范围，取绝对值最小的输出。
    if (minx > 0)
        printf("%d", (int)ceil(minx)); // maxxn>minx>0，答案为minx上取整
    else if (maxx < 0)
        printf("%d", (int)floor(maxx)); // minx<maxxn<0，答案为maxxn下取整
    else
        puts("0"); // minx<0<maxxn，显然是0绝对值最小
    // 此处应有minx>maxxn，输出"NO SOLUTION"的情况，不过其实并没有这个点，所以就省略了。
    return 0;
}