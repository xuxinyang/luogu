#include <bits/stdc++.h>
using namespace std;
#define ll long long
int m[7][7], flag, dep;
const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
const char *goa = "1111101111002110000100000";  // 目标状态
int t, sx, sy;
int h()
{
    int cnt = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cnt += m[i][j] != goa[i*5+j]-'0';
    return cnt;
}
void dfs(int g, int x, int y)
{  
    if (g == dep)
    {
        if (!h()) flag = 1;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 0 || xx >= 5 || yy < 0 || yy >= 5) continue;
        swap(m[x][y], m[xx][yy]);
        if (g + h() <= dep) dfs(g+1, xx, yy);
        swap(m[x][y], m[xx][yy]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        flag = 0;
        for (int i = 0 ; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                char ch;
                cin >> ch;
                if (ch == '*') m[i][j] = 2, sx = i, sy = j;
                else m[i][j] = ch - '0';
            }
        }
        for (dep = 0; dep <= 15; dep++)
        {
            dfs(0, sx, sy);
            if (flag) 
            {
                cout << dep << "\n";
                break;
            }
        }
        if (!flag) cout << -1 << "\n";
    }
    return 0;
}