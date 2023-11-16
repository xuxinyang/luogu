#include <bits/stdc++.h>
using namespace std;
int k, n, a[25], c = 0;
bool vis[25][25];
int main()
{
    cin >> k >> n;
    memset(vis, 1, sizeof(vis));
    while (k--)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) vis[a[i]][a[i]] = false;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                vis[a[j]][a[i]] = false;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (vis[i][j]) c++;
    cout << c;
    return 0;
}