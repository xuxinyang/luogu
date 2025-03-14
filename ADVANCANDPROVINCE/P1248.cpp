#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int n, a[maxn], b[maxn], t[maxn];
struct Node
{
    int id, m;
} nodes[maxn];
bool cmp(Node A, Node B)
{
    return A.m < B.m;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
        nodes[i].m = min(a[i], b[i]);
        nodes[i].id = i;
    }
    sort(nodes + 1, nodes + 1 + n, cmp);
    int l = 0, r = n + 1;
    for (int i = 1; i <= n; i++)
    {
        if (nodes[i].m == a[nodes[i].id]) t[++l] = nodes[i].id;
        else t[--r] = nodes[i].id;
    }
    int ta = 0, tb = 0;
    for (int i = 1; i <= n; i++)
    {
        ta += a[t[i]];
        if (ta > tb) tb = ta;
        tb += b[t[i]];
    }
    printf("%d\n", tb);
    for (int i = 1; i <= n; i++) printf("%d ", t[i]);
    return 0;
}