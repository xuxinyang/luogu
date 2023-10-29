#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const int maxn = 2e5+5;
int n, l, r, a[maxn], f[maxn];
struct Node
{
    int v, num;
};
deque<Node> q;

int main()
{
    cin >> n >> l >> r;
    for (int i = 0; i <= n; ++i) cin >> a[i];
    int p = 0;
    memset(f, 0xc0, sizeof(f));
    f[p] = 0;
    for (int i = l; i <= n; ++i)
    {
        while (!q.empty() && q.back().v < f[p]) q.pop_back();
        q.push_back((Node){f[p], p});
        while (q.front().num + r < i) q.pop_front();
        f[i] = q.front().v + a[i];
        ++p;
    }
    int ans = -inf;
    for (int i = n - r + 1; i <= n; ++i)
        ans = max(ans, f[i]);
    cout << ans;
    return 0;
}