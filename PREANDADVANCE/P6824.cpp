#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int n, k, a[maxn], ans;
int tot, trie[maxn<<2][2], sz[maxn<<2];
void insert(int x)
{
    int p = 0, c;
    for (int k = 21; k >= 0; k--)
    {
        c = (x >> k) & 1;
        if (!trie[p][c]) trie[p][c] = ++tot;
        p = trie[p][c];
        sz[p]++;
    }
}
int query(int x)
{
    int ret = 0, p = 0, c;
    bool flag = 0;
    for (int i = 21; i >= 0; i--)
    {
        c = (x >> i) & 1;
        int t = (k >> i) & 1;
        if (t == 1) ret += sz[trie[p][1-(c^t)]];
        if (!trie[p][c^t])
        {
            flag = 1;
            break;
        }
        p = trie[p][c^t];
    }
    if (!flag) ret += sz[p];
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }
    for (int i = 0; i < 2097152; i++)
    {
        ans = max(ans, query(i));
        if (ans == n) break;
    }
    cout << ans;
    return 0;
}