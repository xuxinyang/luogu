#include <cstdio>
#define ll long long
const int MAXN = 100005 * 2;
ll tree[MAXN * 4], tag[MAXN * 4], a[MAXN], cnt;
void push_up(ll now)
{
    tree[now] = tree[now * 2] + tree[now * 2 + 1];
}
void build(ll now, ll l, ll r)
{
    if (l == r)
    {
        cnt++;
        tree[now] = a[cnt];
    }
    else
    {
        ll mid = (l + r) >> 1;
        build(now * 2, l, mid);
        build(now * 2 + 1, mid + 1, r);
        push_up(now);
    }
}
void push_down(ll now, ll l, ll r)
{
    ll mid = (l + r) >> 1;
    tree[now * 2] += (mid - l + 1) * tag[now];
    tree[now * 2 + 1] += (r - mid) * tag[now];
    tag[now * 2] += tag[now];
    tag[now * 2 + 1] += tag[now];
    tag[now] = 0;
    push_up(now);
}
void update(ll now, ll l, ll r, ll x, ll y, ll t)
{
    if (x <= l && y >= r)
    {
        tree[now] += (r - l + 1) * t;
        tag[now] += t;
    }
    else
    {
        push_down(now, l, r);
        ll mid = (l + r) >> 1;
        if (x <= mid)
            update(now * 2, l, mid, x, y, t);
        if (y > mid)
            update(now * 2 + 1, mid + 1, r, x, y, t);
        push_up(now);
    }
}
ll query(ll now, ll l, ll r, ll x, ll y)
{
    ll ans = 0;
    if (x <= l && y >= r)
    {
        ans += tree[now];
    }
    else
    {
        push_down(now, l, r);
        ll mid = (l + r) >> 1;
        if (x <= mid)
            ans += query(now * 2, l, mid, x, y);
        if (y > mid)
            ans += query(now * 2 + 1, mid + 1, r, x, y);
    }
    return ans;
}
int main()
{
    ll n, f, x;
    scanf("%lld %lld", &n, &f);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    build(1, 1, n);
    for (ll i = 1; i <= f; i++)
    {
        ll num, l, r, k;
        scanf("%lld", &num);
        if (num == 1)
        {
            scanf("%lld %lld %lld", &l, &r, &k);
            update(1, 1, n, l, r, k);
        }
        if (num == 2)
        {
            scanf("%lld", &k);
            update(1, 1, n, 1, 1, k);
        }
        if (num == 3)
        {
            scanf("%lld", &k);
            update(1, 1, n, 1, 1, -1 * k);
        }
        if (num == 4)
        {
            scanf("%lld %lld", &l, &r);
            printf("%lld\n", query(1, 1, n, l, r));
        }
        if (num == 5)
        {
            printf("%lld\n", query(1, 1, n, 1, 1));
        }
    }
    return 0;
}