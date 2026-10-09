#include <bits/stdc++.h>
using namespace std;
constexpr long long inf = 2e18;
constexpr int N = 1e5+5;

int n, m, q, u, v, t;
long long a[N], x, y;
queue<long long> q1, q2, q3;

bool cmp(long long A, long long B)
{
    return A > B;
}

long long findmax()
{
    long long x1 = -inf, x2 = -inf, x3 = -inf;
    if (!q1.empty()) x1 = q1.front();
    if (!q2.empty()) x2 = q2.front();
    if (!q3.empty()) x3 = q3.front();

    long long res;
    if (x1 >= x2 && x1 >= x3)
    {
        res = x1; q1.pop();
    }
    else if (x2 >= x1 && x2 >= x3)
    {
        res = x2; q2.pop();
    }
    else
    {
        res = x3; q3.pop();
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q >> u >> v >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1, cmp);
    for (int i = 1; i <= n; i++)
        q1.push(a[i]);

    for (int i = 1; i <= m; i++)
    {
        x = findmax() + 1LL * q * (i - 1);
        if (i % t == 0)
            cout << x << " ";
        y = x * 1LL * u / v; //整数向下取整，避免浮点误差
        long long z = x - y;

        y -= 1LL * q * i;
        q2.push(y);
        z -= 1LL * q * i;
        q3.push(z);
    }
    cout << "\n";

    for (int i = 1; i <= n+m; i++)
    {
        x = findmax() + 1LL * q * m;
        if (i % t == 0)
            cout << x << " ";
    }
    return 0;
}
