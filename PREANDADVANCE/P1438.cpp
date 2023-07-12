#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;
int n, m;
struct SGT
{
    int initval[maxn];
    ll sumv[maxn<<2];
    ll addv[maxn<<2];
    int left, right;
    ll val;
    void build() { buildtree(1, 1, n); }
    void buildtree(int o, int L, int R)
    {
        if (L == R)
        {
            sumv[o] = addv[o] = initval[L];
            return;
        }
        int M = L + (R - L) / 2;
        int lc = o << 1;
        int rc = lc | 1;
        buildtree(lc, L, M);
        buildtree(rc, M + 1, R);
        addv[o] = 0;
        sumv[o] = sumv[lc] + sumv[rc];
    }
    void add(int L, int R, ll v)
    {
        left = L;
        right = R;
        val = v;
        addtree(1, 1, n);
    }
    void addtree(int o, int L, int R)
    {
        if (L >= left && R <= right)
        {
            addv[o] += val;
            maintain(o, L, R);
            return;
        }
        int M = L + (R - L) / 2;
        int lc = o << 1;
        int rc = lc | 1;
        if (left <= M)
            addtree(lc, L, M);
        if (right > M)
            addtree(rc, M + 1, R);
        maintain(o, L, R);
    }
    void maintain(int o, int L, int R)
    {
        sumv[o] = addv[o] * (R - L + 1);
        if (L != R)
        {
            int lc = o << 1;
            int rc = lc | 1;
            sumv[o] += sumv[lc] + sumv[rc];
        }
    }
    ll query(int L, int R)
    {
        left = L;
        right = R;
        val = 0;
        querytree(1, 1, n, 0);
        return val;
    }
    void querytree(int o, int L, int R, ll addval)
    {
        if (left <= L && right >= R)
        {
            val += sumv[o] + addval * (R - L + 1);
            return;
        }
        int M = L + (R - L) / 2;
        int lc = o << 1;
        int rc = lc | 1;
        if (left <= M)
            querytree(lc, L, M, addval + addv[o]);
        if (right > M)
            querytree(rc, M + 1, R, addval + addv[o]);
    }
};
int a[100010];
SGT sgt;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        sgt.initval[i] = a[i] - a[i - 1];
    }
    sgt.build();
    for (int i = 0; i < m; ++i)
    {
        int order;
        scanf("%d", &order);
        if (order == 1)
        {
            int l, r, k, d;
            scanf("%d%d%d%d", &l, &r, &k, &d);
            sgt.add(l, l, k);
            if (l != r)
                sgt.add(l + 1, r, d);
            if (r != n)
                sgt.add(r + 1, r + 1, -k - d * (r - l));
        }
        else
        {
            int p;
            scanf("%d", &p);
            cout << sgt.query(1, p) << endl;
        }
    }
    return 0;
}