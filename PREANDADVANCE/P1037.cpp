#include <bits/stdc++.h>
using namespace std;
string s;
int k, vis[15][15], f[15], ans[105] = {0, 1};
void floyd()
{
    for (int k = 0; k <= 9; k++)
    {
        for (int i = 0; i <= 9; i++)
        {
            for (int j = 0; j <= 9; j++)
                vis[i][j] = vis[i][j] || (vis[i][k] && vis[k][j]);
        }
    }
}
int main()
{
    int x, y;
    cin >> s >> k;
    while (k--)
    {
        cin >> x >> y;
        vis[x][y] = 1;
    }
    for (int i = 0; i <= 9; i++) vis[i][i] = 1;
    floyd();
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (vis[i][j]) f[i]++;
        }
    }
    int len = 2;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 1; j <= 100; j++) ans[j] *= f[s[i]-'0'];
        for (int j = 1; j <= 100; j++)
        {
            if (ans[j] >= 0)
                ans[j+1] += ans[j]/10, ans[j] %= 10;
        }
        while (ans[len]) len++;
    }
    for (int i = len-1; i >= 1; i--) cout << ans[i];
    return 0;
}