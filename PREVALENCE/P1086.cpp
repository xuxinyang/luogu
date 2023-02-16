#include <bits/stdc++.h>
using namespace std;
int m, n, tim, k, ans;
struct Peanut
{
    int x, y, cnt;
};
Peanut peas[405];
int a[25][25];
bool cmp(Peanut p, Peanut q)
{
    return p.cnt > q.cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n >> tim;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j]) peas[++k].x = i, peas[k].y = j, peas[k].cnt = a[i][j];
        }
    }
    sort(peas + 1, peas + k + 1, cmp);
    for (int j = 1; j <= k; j++)
    {
        if (j == 1) 
            if (peas[j].x * 2 + 1  <= tim) ans += peas[j].cnt, tim -= (peas[j].x + 1);
            else break;
        else
        {
            int cost_jump = abs(peas[j].x - peas[j-1].x) + abs(peas[j].y - peas[j-1].y);
            int cost_back = peas[j].x;
            if (cost_jump + cost_back + 1 <= tim)
            {
                ans += peas[j].cnt;
                tim -= (cost_jump + 1);
            }
            else
            {
                break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}