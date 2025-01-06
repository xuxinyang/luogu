#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
const int inf = 0x3f3f3f3f;
int t, n, a[maxn], ans;
// 找顺子：三顺子、双顺子、单顺子
// 带牌：三代一、三代一对、四代二、
// 剩余：对子、单牌
void dfs(int x) // x 表示出牌次数
{
    if (x >= ans) return;
    int k = 0; // 单顺子
    for (int i = 3; i <= 14; i++)
    {
        if (!a[i]) k = 0;
        else
        {
            k++;
            if (k >= 5)
            {
                for (int j = i; j >= i-k+1; j--) a[j]--;
                dfs(x+1);
                for (int j = i; j >= i-k+1; j--) a[j]++;
            }
        }
    }
    k = 0;  // 双顺子
    for (int i = 3; i <= 14; i++)
    {
        if (a[i] <= 1) k = 0;
        else
        {
            k++;
            if (k >= 3)
            {
                for (int j = i; j >= i-k+1; j--) a[j]-=2;
                dfs(x+1);
                for (int j = i; j >= i-k+1; j--) a[j]+=2;
            }
        }
    }
    k = 0;  // 三顺子
    for (int i = 3; i <= 14; i++)
    {
        if (a[i] <= 2) k = 0;
        else
        {
            k++;
            if (k >= 2) 
            {
                for (int j = i; j >= i-k+1; j--) a[j]-=3;
                dfs(x+1);
                for (int j = i; j >= i-k+1; j--) a[j]+=3;
            }
        }
    }
    for (int i = 2; i <= 14; i++)
    {
        if (a[i] <= 3)
        {
            if (a[i] <= 2) continue;
            a[i]-=3;
            for (int j = 2; j <= 15; j++)
            {
                if (a[j] <= 0 || j == i) continue;
                a[j]--;
                dfs(x+1);
                a[j]++;
            }
            for (int j = 2; j <= 14; j++)
            {
                if (a[j] <= 1 || j == i) continue;
                a[j] -= 2;
                dfs(x+1);
                a[j] += 2;
            }
            a[i] += 3;
        }
        else
        {
            a[i] -= 3;
            for (int j = 2; j <= 15; j++)
            {
                if (a[j] <= 0 || j == i) continue;
                a[j]--;
                dfs(x+1);
                a[j]++;
            }
            for (int j = 2; j <= 14; j++)
            {
                if (a[j] <= 1 || j == i) continue;
                a[j]-=2;
                dfs(x+1);
                a[j]+=2;
            }
            a[i] += 3;
            a[i] -= 4;
            for (int j = 2; j <= 15; j++)
            {
                if (a[j] <= 0 || j == i) continue;
                a[j]--;
                for (int k = 2; k <= 15; k++)
                {
                    if (a[k] <= 0 || j == k) continue;
                    a[k]--;
                    dfs(x+1);
                    a[k]++;
                }
                a[j]++;
            }
            for (int j = 2; j <= 14; j++)
            {
                if (a[j] <= 1 || i == j) continue;
                a[j] -= 2;
                for (int k = 2; k <= 14; k++)
                {
                    if (a[k] <= 1 || j == k) continue;
                    a[k] -= 2;
                    dfs(x+1);
                    a[k] += 2;
                }
                a[j] += 2;
            }
            a[i] += 4;
        }
    }
    for (int i = 2; i <= 15; i++) if (a[i]) x++;
    ans = min(ans, x);
}
void solve()
{
    memset(a, 0, sizeof a);
    int x, c;
    ans = inf;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> c;
        if (x == 0) a[15]++;
        else if (x == 1) a[14]++;
        else a[x]++;
    }
    dfs(0);
    cout << ans << "\n";
}
int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t >> n;
    while (t--) solve();
    return 0;
}