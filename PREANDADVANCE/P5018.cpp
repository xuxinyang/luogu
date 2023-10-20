#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6+5;
struct Tree
{
    ll left, right, val;
};
Tree trees[maxn];
ll n, ans;
bool dfs(ll x, ll y)
{
    if (x == -1 && y == -1) return true;
    else if (x * y < 0 || trees[x].val != trees[y].val) return false;
    else return dfs(trees[x].left, trees[y].right) && dfs(trees[x].right, trees[y].left);
}
ll stati(ll now)
{
    if (now == -1) return 0;
    else return stati(trees[now].left) + stati(trees[now].right) + 1;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> trees[i].val;
    for (int i = 1; i <= n; i++)
    {
        cin >> trees[i].left >> trees[i].right;
    }
    for (int i = 1; i <= n; i++)
    {
        if (dfs(i, i)) ans = max(ans, stati(i));
    }
    cout << ans;
    return 0;
}