#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
int a, b, c, d, m, g;
int w[maxn], v[maxn], n[maxn], f[maxn];
void zeroonePack(int w, int v)
{
    for (int i = m; i >= w; i--)
        f[i] = max(f[i], f[i-w] + v);
}
void completePack(int w, int v)
{
    for (int i = w; i <= m; i++)
        f[i] = max(f[i], f[i-w] + v);
}
void multipPack(int w, int v, int n)
{
    if (m <= n * w || n == 0)
    {
        completePack(w, v);
        return;
    }
    else
    {
        int k = 1;
        while (k <= n)
        {
            zeroonePack(k*w, k*v);
            n -= k;
            k *= 2;
        }
    }
    zeroonePack(n*w, n*v);
}
int main()
{
    scanf("%d:%d %d:%d", &a, &b, &c, &d);
    if (b > d) m = 60 - b + d + (c - a - 1) * 60;
    else m = (c - a) * 60 + d - b;
    cin >> g;
    for (int i = 1; i <= g; i++)
        scanf("%d%d%d", &w[i], &v[i], &n[i]);
    for (int i = 1; i <= g; i++)
        multipPack(w[i], v[i], n[i]);
    cout << f[m];
    return 0;
}