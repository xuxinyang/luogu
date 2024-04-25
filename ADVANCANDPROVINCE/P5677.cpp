// 树状数组+排序 O(nlogn)
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

#define N 300005
#define LL long long
#define lowb(x) x & -x
int n, m, cnt; // cnt:记录好对个数
LL ans, s[N];  // s[x]:左端点在[x−lowb(x)+1,x]内的好对个数

struct A
{
    LL v;
    int pos;
} a[N]; // 数
struct P
{
    int l, r;
} p[N * 2]; // 好对
struct Q
{
    int l, r, pos;
} q[N]; // 询问
bool cmp1(A a, A b)
{ // 数按值排序
    return a.v < b.v;
}
bool cmp2(P a, P b)
{ // 好对按右端点排序
    return a.r != b.r ? a.r < b.r : a.l < b.l;
}
bool cmp3(Q a, Q b)
{ // 询问按右端点排序
    return a.r != b.r ? a.r < b.r : a.l < b.l;
}
void add(A a, A b)
{ // 好对位置小的放前面
    p[++cnt].l = min(a.pos, b.pos);
    p[cnt].r = max(a.pos, b.pos);
}
void change(int x, int k)
{ // 向后修
    while (x <= n)
        s[x] += k, x += lowb(x);
}
int query(int x)
{ // 向前查
    int t = 0;
    while (x)
        t += s[x], x -= lowb(x);
    return t;
}
int main()
{
    scanf("%d%d", &n, &m);
    if (n == 1)
    {
        puts("0");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i].v), a[i].pos = i;
    sort(a + 1, a + 1 + n, cmp1); // 数按值排序

    add(a[1], a[2]);
    add(a[n], a[n - 1]);
    for (int i = 2; i < n; i++)
    {
        int ld = a[i].v - a[i - 1].v, rd = a[i + 1].v - a[i].v;
        if (ld < rd)
            add(a[i], a[i - 1]);
        else if (ld > rd)
            add(a[i], a[i + 1]);
        else
            add(a[i], a[i - 1]), add(a[i], a[i + 1]);
    }
    sort(p + 1, p + 1 + cnt, cmp2); // 好对按右端点排序

    for (int i = 1; i <= m; i++)
        scanf("%d%d", &q[i].l, &q[i].r), q[i].pos = i;
    sort(q + 1, q + 1 + m, cmp3); // 询问按右端点排序

    // 每次qr右移，将右端点<=qr的好对都加入到树状数组里，
    // 再减去左端点在[1,ql−1]内的好对个数就是答案
    for (int i = 1, j = 1; i <= m; i++)
    {
        for (; p[j].r <= q[i].r && j <= cnt; j++)
            change(p[j].l, 1);
        ans += 1ll * q[i].pos * (j - 1 - query(q[i].l - 1));
    }
    printf("%lld", ans);
}