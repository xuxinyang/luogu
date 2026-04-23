#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e4+5;
int n, fa[N*3], m, ans;
int find(int x)
{
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
int main()
{
    cin.tie(nullptr) ->  sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n*3; i++) fa[i] = i;
    while (m--)
    {
        int op, u, v;
        cin >> op >> u >> v;
        if (u > n || v > n)
        {
            ans ++;
            continue;
        }
        if (op == 1)
        {
            if (find(u+n) == find(v) || find(u) == find(v+n)) ans++;
            else
            {
                fa[find(u)] = find(v);
                fa[find(u+n)] = find(v+n);
                fa[find(u+2*n)] = find(v+2*n);
            }
        }
        else
        {
            if (find(u) == find(v) || find(u) == find(v+n)) ans++;
            else
            {
                fa[find(u+n)] = find(v);
                fa[find(u+n*2)] = find(v+n);
                fa[find(u)] = find(v+n*2);
            }
        }
    }
    cout << ans;
    return 0;
}