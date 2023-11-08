#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6+5;
struct Seg
{
    int l, r;
    bool operator < (const Seg &x) const {return r < x.l;}
    Seg(int _l, int _r) : l(_l), r(_r) {}
};
int f[maxn][25], L[maxn], R[maxn], t[maxn], cnt, n, k, sum;
set<Seg> s;
int query(int l, int r)
{
    int res = 0;
    for (int i = 20; i >= 0; i--)
    {
        if (f[l][i] <= r + 1) res += 1 << i, l = f[l][i];
    }
    return res;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> L[i] >> R[i], t[++cnt] = L[i], t[++cnt] = R[i];
    sort(t + 1, t + cnt + 1);
    cnt = unique(t + 1, t + cnt + 1) - t;
    for (int i = 1; i <= n; i++) L[i] = lower_bound(t + 1, t + cnt + 1, L[i]) - t, R[i] = lower_bound(t + 1, t + cnt + 1, R[i]) - t;
    for (int i = 1; i <= cnt + 5; i++)
        for (int j = 0; j <= 20; j++) f[i][j] = cnt + 5;
    for (int i = 1; i <= n; i++) f[L[i]][0] = min(f[L[i]][0], R[i]);
    for (int i = cnt; i >= 1; i--)
    {
        f[i][0] = min(f[i][0], f[i+1][0]);
        for (int j = 1; j <= 20; j++)
            f[i][j] = min(f[i+1][j], f[f[i][j-1]][j-1]);
    }
    s.insert(Seg(1, cnt));
    sum = query(1, cnt);
    if (sum < k)
    {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (s.find(Seg(L[i], R[i]-1)) == s.end()) continue;
        Seg now = *s.find(Seg(L[i], R[i]-1));
        if (L[i] >= now.l && R[i] - 1 <= now.r)
        {
            int ans = query(now.l, L[i]-1) + query(R[i], now.r) - query(now.l, now.r);
            if (sum + ans >= k - 1)
            {
                cout << i << "\n";
                s.erase(now), k--;
                sum += ans;
                if (now.l < L[i]) s.insert(Seg(now.l, L[i] - 1));
                if (now.r >= R[i]) s.insert(Seg(R[i], now.r));
            }
        }
        if (!k) break;
    }
    return 0;
}