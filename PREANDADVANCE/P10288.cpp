#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+5;
struct Node
{
    int x, l, r, id;
};
Node nodes[maxn];
int t, n, q, a[maxn], b[maxn], c[maxn];
int k, m[maxn], res[maxn];
bool cmp(Node x, Node y)
{
    if (x.l/k != y.l/k) return x.l > y.l;
    else if (x.l%k) return x.r < y.r;
    else return x.r > y.r;
}
void add(int x) {m[a[x]]++;}
void del(int x) {m[a[x]]--;}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        memset(m, 0, sizeof(m));
        int len = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b+1, b+n+1);
        for (int i = 1; i <= n; i++)
        {
            if (b[i] == b[i-1]) continue;
            c[++len] = b[i];
        }
        for (int i = 1; i <= n; i++)
            a[i] = lower_bound(c+1, c+1+len, a[i])-c;
        cin >> q;
        k = sqrt(q);    // 分块
        for (int i = 1; i <= q; i++)
        {
            cin >> nodes[i].l >> nodes[i].r >> nodes[i].x;
            int h = lower_bound(c+1, c+len+1, nodes[i].x) - c;
            if (c[h] == nodes[i].x) nodes[i].x = h;
            else nodes[i].x = n + 1;
            nodes[i].id = i;
        }
        sort(nodes+1, nodes+q+1, cmp);
        int l = 0, r = 0;
        for (int i = 1; i <= q; i++)
        {
            while (nodes[i].l < l) add(--l);
            while (nodes[i].l > l) del(l++);
            while (nodes[i].r < r) del(r--);
            while (nodes[i].r > r) add(++r);
            res[nodes[i].id] = m[nodes[i].x];
        }
        for (int i = 1; i <= q; i++) cout << res[i] << "\n";
    }
    return 0;
}