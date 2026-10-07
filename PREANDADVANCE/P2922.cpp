#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n, m, k, ch[N][3], tot = 1, bo[N], sum[N], x;
bool p[N];
void add(bool p[])
{
    int u = 1;
    for (int i = 1; i <= k; i++)
    {
        int c = p[i];
        if (ch[u][c] == -1) ch[u][c] = ++tot;
        u = ch[u][c];
        sum[u]++;
    }
    bo[u]++;
}
int find(bool p[])
{
    int u = 1;
    int res = 0;
    for (int i = 1; i <= k; i++)
    {
        int c = p[i];
        if (ch[u][c] == -1) return res;
        u = ch[u][c];
        res += bo[u];
    }
    return res - bo[u] + sum[u];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x;
    cin >> m >> n;
    memset(ch, -1, sizeof ch);
    for (int i = 1; i <= m; i++)
    {
        cin >> k;
        for (int j = 1; j <= k; j++) cin >> p[j];
        add(p);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        for (int j = 1; j <= k; j++) cin >> p[j];
        cout << find(p) << "\n";
    }
    return 0;
}