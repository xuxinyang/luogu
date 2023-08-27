#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e4+5;
const int maxm = 5e4+5;
int n, m, k, a[maxn], pos[maxn], siz, cnt[maxn];
ll ans[maxn], res;
struct Qm
{
    int l, r, k;
};
Qm qms[maxm];
void add(int id)
{
    res -= cnt[a[id]] * cnt[a[id]];
    cnt[a[id]]++;
    res += cnt[a[id]] * cnt[a[id]];
}
void sub(int id)
{
    res -= cnt[a[id]] * cnt[a[id]];
    cnt[a[id]]--;
    res += cnt[a[id]] * cnt[a[id]];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    siz = sqrt(n);
    for (int i = 1; i <= n; i++) cin >> a[i], pos[i] = (i-1) / siz;
    for (int i = 1; i <= m; i++) cin >> qms[i].l >> qms[i].r, qms[i].k = i;
    sort(qms + 1, qms + m + 1, [](Qm x, Qm y){
        return pos[x.l] == pos[y.l] ? x.r < y.r : pos[x.l] < pos[y.l];
    });
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++)
    {
        while (qms[i].l < l) add(--l);
        while (qms[i].r > r) add(++r);
        while (qms[i].l > l) sub(l++);
        while (qms[i].r < r) sub(r--);
        ans[qms[i].k] = res; 
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << "\n";
    return 0;
}