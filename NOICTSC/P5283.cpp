#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N = 5e5+5;
int n, k;
ll a[N];
int trie[N<<5][2], sz[N<<5], tot;
void insert(ll val)
{
    int u = 0;
    for (int i = 31; i >= 0; --i)
    {
        int z = (val >> i) & 1;
        if (!trie[u][z]) trie[u][z] = ++tot;
        u = trie[u][z];
        sz[u]++;
    }
}
ll find(ll val, int t)
{
    ll s = 0;
    int u = 0;
    for (int i = 31,z; i >= 0; --i)
    {
        z = (val >> i) & 1;
        if (sz[trie[u][z^1]] >= t)
        {
            u = trie[u][z^1];
            s |= (1ll << i);
        }
        else
        {
            t -= sz[trie[u][z^1]];
            u = trie[u][z];
        }
    }
    return s;
}
struct Node {
    ll w;
    int x, y;
    bool operator < (const Node & A) const {
        return w < A.w;
    }
};
Node d[N];
priority_queue<Node> q;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] ^= a[i-1];
    for (int i = 0; i <= n; i++) insert(a[i]);
    k = 2 * k;
    for (int i = 0; i <= n; i++) {
        d[i].w = find(a[i], 1);
        d[i].x = i, d[i].y = 1;
        q.push(d[i]);
    }
    ll ans = 0;
    Node A;
    for (int i = 1; i <= k; i++)
    {
        A = q.top();
        ans += A.w;
        q.pop();
        d[A.x].y++;
        d[A.x].w = find(a[A.x], d[A.x].y);
        q.push(d[A.x]);
    }
    ans /= 2;
    printf("%lld", ans);
    return 0;
}