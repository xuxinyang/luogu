#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e4+5;
int n, mp[maxn][maxn], de[maxn], s, cnt, tot, path[maxn];
char x, y;
int al2num(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 27;
    else
        return c - 'A' + 1;
}
char num2al(int x)
{
    if (x < 27)
        return x - 1 + 'A';
    else
        return x - 27 + 'a';
}
void dfs(int u)
{
    for (int i = 1; i <= 52; i++)
    {
        if (mp[u][i] > 0)
        {
            mp[u][i]--;
            mp[i][u]--;
            dfs(i);
        }
    }
    path[++tot] = u;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        de[al2num(x)]++, de[al2num(y)]++;
        mp[al2num(x)][al2num(y)]++;
        mp[al2num(y)][al2num(x)]++;
    }
    s = inf;
    for (int i = 1; i <= 52; i++)
    {
        if (de[i] % 2 == 1)
            s = min(s, i), cnt++;
    }
    if (cnt != 0 && cnt != 2)
    {
        cout << "No Solution\n";
        return 0;
    }
    if (cnt == 0)
    {
        for (int i = 1; i <= 52; i++)
        {
            if (de[i])
            {
                s = i;
                break;
            }
        }
    }
    dfs(s);
    for (int i = tot; i >= 1; i--)
    {
        cout << num2al(path[i]);
    }
    return 0;
}