#include <bits/stdc++.h>
using namespace std;
int n, t[30], cnt;
int a[30], b[30], c[30], nxt[30];
bool vis[30];
bool check()
{
    int carry = 0;
    for (int i = n-1; i >= 0; i--)
    {
        if ((t[a[i]]+t[b[i]]+carry)%n != t[c[i]]) return 0;
        carry = (t[a[i]]+t[b[i]]+carry)/n;
    }
    return 1;
}
void dfs(int idx)
{
    if (t[a[0]]+t[b[0]] >= n) return;
    for (int i = n-1; i >= 0; i--)
    {
        int t1 = t[a[i]], t2 = t[b[i]], t3 = t[c[i]];
        if (t1 == -1 || t2 == -1 || t3 == -1) continue;
        if ((t1+t2)%n != t3 && (t1+t2+1)%n != t3) return;
    }
    if (idx == n)
    {
        // for (int i = 1; i <= n; i++) cout << t[i] << " ";
        if (check())
        {
            for (int i = 0; i < n; i++) cout << t[i] << " ";
            exit(0);
        }
        return;
    }
    for (int i = n-1; i >= 0; i--)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            t[nxt[idx]] = i;
            dfs(idx+1);
            vis[i] = 0;
            t[nxt[idx]] = -1;
        }
    }
}
int main()
{
    cin >> n;
    char ch;
    for (int i = 0; i < n; i++) {cin >> ch; a[i] = ch-'A';}
    for (int i = 0; i < n; i++) {cin >> ch; b[i] = ch-'A';}
    for (int i = 0; i < n; i++) {cin >> ch; c[i] = ch-'A';}
    memset(t, -1, sizeof(t));
    for (int i = n-1; i >= 0; i--)
    {
        if (!vis[a[i]]) vis[a[i]] = 1, nxt[cnt++] = a[i];
        if (!vis[b[i]]) vis[b[i]] = 1, nxt[cnt++] = b[i];
        if (!vis[c[i]]) vis[c[i]] = 1, nxt[cnt++] = c[i];
    }
    memset(vis, 0, sizeof(vis));
    dfs(0);
    return 0;
}