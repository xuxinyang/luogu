#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, len[15][15];
map<char, int> mp;
string s[15][15];
bool vis[15], f;
bool check()
{
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            int sum = 0;
            int power = 1;
            for (int k = len[i][j]-1; k >= 0; k--)
            {
                sum += power * mp[s[i][j][k]];
                power *= (n-1);
            }
            if (sum != mp[s[i][1][0]] + mp[s[1][j][0]]) return false;
        }
    }
    return true;
}
void dfs(int p)
{
    if (p == n)
    {
        if (check())
        {
            f = 1;
            for (int i = 2; i <= n; i++)
            {
                cout << s[1][i][0] << "=" << mp[s[1][i][0]] << " ";
            }
            cout << "\n" << n-1;
            exit(0);
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (vis[i]) continue;
        mp[s[1][p+1][0]] = i;
        vis[i] = 1;
        dfs(p + 1);
        vis[i] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> s[i][j];
            len[i][j] = s[i][j].size();
        }
    }
    dfs(1);
    if (!f) cout << "ERROR!";
    return 0;
}