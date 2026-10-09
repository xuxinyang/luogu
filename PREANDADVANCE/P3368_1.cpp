#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5+5;
int n, m, a[N], b[N], c[N];
int lowbit(int x) {return x & -x;}
void add(int x, int y)
{
    for (int i = x; i <= n; i += lowbit(i)) c[i] += y;
}
int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += c[i];
    return res;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i] - a[i-1];
        add(i, b[i]);
    }
    while (m--)
    {
        int op, x, y;
        cin >> op;
        if (op == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            add(x, k);
            add(y+1, -k);
        }
        else 
        {
            int x;
            cin >> x;
            cout << sum(x) << "\n";
        }
    }
    return 0;
}