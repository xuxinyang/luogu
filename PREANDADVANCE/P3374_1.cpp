#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5+5;
int n, m, a[N], c[N];
int lowbit(int x)
{
    return x & -x;
}
int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += c[i];
    return res;
}
void add(int x, int y)
{
    for (int i = x; i <= n; i+=lowbit(i)) c[i] += y; 
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        add(i, a[i]);
    }
    while (m--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) add(x, y);
        else cout << sum(y)-sum(x-1) << "\n";
    }
    return 0;
}