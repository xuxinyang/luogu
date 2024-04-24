#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
struct Node
{
    int val, pos; // 值，位置
};
Node a[maxn];
int n, s[maxn];
long long ans;
int lowbit(int x)
{
    return x & (-x);
}
void update(int x, int k)
{
    while (x <= n)
        s[x] += k, x += lowbit(x);
}
int query(int x)
{
    int t = 0;
    while (x)
        t += s[x], x -= lowbit(x);
    return t;
}
int cmp(Node x, Node y)
{
    if (x.val == y.val)
        return x.pos > y.pos;
    else
        return x.val > y.val;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].val;
        a[i].pos = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        ans += query(a[i].pos - 1);
        update(a[i].pos, 1);
    }
    cout << ans;
    return 0;
}