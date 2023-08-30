#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
const int maxm = 2e5+5;
int n, m, rp, siz, a[maxn], pos[maxn], ans[maxm], cnt[maxn], t[maxn], d[maxn];
struct QM
{
    int l, r, k;
};
QM qms[maxm];
void add(int idx)
{
    t[cnt[a[idx]]]--;
    t[++cnt[a[idx]]]++;
    rp = max(rp, cnt[a[idx]]);
}
void sub(int idx)
{
    t[cnt[a[idx]]]--;
    if (cnt[a[idx]] == rp && !t[cnt[a[idx]]]) rp--;
    t[--cnt[a[idx]]]++;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    siz = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = a[i];
        pos[i] = (i-1) / siz;
    }
    sort(d + 1, d + n + 1);
    int len = unique(d + 1, d + n + 1) - d - 1;
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(d + 1, d + n + 1, a[i]) - d - 1;
    for (int i = 1; i <= m; i++)
    {
        cin >> qms[i].l >> qms[i].r;
        qms[i].k = i;
    }
    sort(qms + 1, qms + m + 1, [](QM x, QM y){
        return pos[x.l] == pos[y.l] ? x.r < y.r : pos[x.l] < pos[y.l];
    });
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++)
    {
        while (qms[i].l < l) add(--l);
        while (qms[i].r > r) add(++r);
        while (qms[i].l > l) sub(l++);
        while (qms[i].r < r) sub(r--); 
        ans[qms[i].k] = -rp;
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << "\n";
    return 0;
}