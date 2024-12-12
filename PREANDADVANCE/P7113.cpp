#include <bits/stdc++.h>
using namespace std;
#define ll __int128
const int maxn = 1e5 + 5;
vector<int> ve[maxn];
int n, m, in[maxn], out[maxn], siz[maxn], tot;
struct Node
{
    ll fm, fz;
};
Node nodes[maxn];
queue<int> q;
ll gcd(ll x, ll y)
{
    if (x % y == 0)
        return y;
    else
        return gcd(y, x % y);
}
void calc(int idx)
{
    ll fac = gcd(nodes[idx].fm, nodes[idx].fz);
    nodes[idx].fm /= fac, nodes[idx].fz /= fac;
}
void add(int a, int b)
{
    ll _gcd = gcd(nodes[a].fm, nodes[b].fm);
    ll _lcm = nodes[a].fm / _gcd * nodes[b].fm;
    nodes[a].fz = nodes[a].fz * (_lcm / nodes[a].fm);
    nodes[b].fz = nodes[b].fz * (_lcm / nodes[b].fm);
    nodes[a].fz += nodes[b].fz;
    nodes[a].fm = nodes[b].fm = _lcm;
    if (nodes[a].fz)
        calc(a);
}
void topo()
{
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (siz[cur])
            nodes[cur].fm *= siz[cur];
        if (nodes[cur].fz)
            calc(cur);
        for (int i = 0; i < siz[cur]; i++)
        {
            int v = ve[cur][i];
            in[v]--;
            add(v, cur);
            if (in[v] == 0)
                q.push(v);
        }
    }
}
void print(ll x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int d, x;
        cin >> d;
        siz[i] = d;
        if (d == 0)
            out[++tot] = i;
        nodes[i].fm = 1;
        for (int j = 1; j <= d; j++)
        {
            cin >> x;
            in[x]++;
            ve[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!in[i])
        {
            nodes[i].fz = 1;
            q.push(i); // 将入度为0的点（即污水输入口）入队
        }
    }
    topo();
    for (int i = 1; i <= tot; i++)
    {
        calc(out[i]);
        print(nodes[out[i]].fz);
        printf(" ");
        print(nodes[out[i]].fm);
        printf("\n");
    }
    return 0;
}