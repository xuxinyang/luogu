#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e4+5;
const int maxm = 5e4+5;
ll n, m, a[maxn], pos[maxn], cnt[maxn];
ll ans_nu[maxm], ans_de[maxm], numerator, denomirator, sum;
struct MQ
{
    int l, r, k;
};
MQ mq[maxm];
ll gcd(ll x, ll y)
{
    return __gcd(x, y);
}
ll fac2(ll x)
{
    if (x < 2) return 0; 
    return x * (x - 1) / 2;
}
void add(int idx)
{
    numerator -= fac2(cnt[a[idx]]);
    cnt[a[idx]]++;
    numerator += fac2(cnt[a[idx]]);
    denomirator = fac2(++sum);
}
void sub(int idx)
{
    numerator -= fac2(cnt[a[idx]]);
    cnt[a[idx]]--;
    numerator += fac2(cnt[a[idx]]);
    denomirator = fac2(--sum);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int siz = sqrt(n);
    
    for (int i = 1; i <= n; i++) cin >> a[i], pos[i] = (i - 1) / siz;
    for (int i = 1; i <= m; i++)
    {
        cin >> mq[i].l >> mq[i].r;
        mq[i].k = i;
    }
    sort(mq + 1, mq + m + 1, [](MQ x, MQ y){
        return pos[x.l] == pos[y.l] ? x.r < y.r : pos[x.l] < pos[y.l];
    });
    
    int l = 1, r = 0;
    for (int i = 1; i <= m; i++)
    {
        while (mq[i].l < l) add(--l);
        while (mq[i].r > r) add(++r);
        while (mq[i].l > l) sub(l++);
        while (mq[i].r < r) sub(r--);
        ans_nu[mq[i].k] = numerator;
        ans_de[mq[i].k] = denomirator;
    }
    for (int i = 1; i <= m; i++)
    {
        if (ans_nu[i] == 0) ans_de[i] = 1;
        else
        {
            ll g = gcd(ans_nu[i], ans_de[i]);
            ans_nu[i] /= g, ans_de[i] /= g;
        }
    }
    for (int i = 1; i <= m; i++)
        cout << ans_nu[i] << "/" << ans_de[i] << "\n";
    return 0;
}