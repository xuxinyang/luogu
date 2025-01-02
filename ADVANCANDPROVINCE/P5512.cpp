#include <bits/stdc++.h>
using namespace std;
const int dis[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int mp[11][11], cur[11][11], n, a[205], prime[205][205], ans;
bool v[205], s[205];

bool check(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dis[i][0], ny = y + dis[i][1];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && cur[nx][ny]!=0 && prime[cur[x][y]][cur[nx][ny]])
            return 0;
    }
    return 1;
}
void dfs3(int x, int y, int sum)
{
    if (sum >= ans) return;
    if (y == n+1) y = 2, x++;
    if (x == n+1)
    {
        ans = sum;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) mp[i][j] = cur[i][j];
        }
        return;
    }
    for (int i = n*n; i >= 1; i--)
    {
        if (v[i]) continue;
        v[i] = 1;
        cur[x][y] = i;
        if (check(x, y)) dfs3(x, y+1, sum);
        v[i] = 0;
        cur[x][y] = 0;
    }
}
void dfs2(int y, int sum)
{
    if (sum >= ans) return;
    if (y == n+1)
    {
        dfs3(2, 2, sum);
        return;
    }
    for (int i = 1; i <= n*n; i++)
    {
        if (v[i]) continue;
        v[i] = 1;
        cur[1][y] = i;
        if (check(1, y)) dfs2(y+1, sum+i);
        v[i] = 0;
        cur[1][y] = 0;
    }
}
void dfs1(int x, int sum)
{
    if (sum >= ans) return;
    if (x == n+1)
    {
        dfs2(2, sum);
        return;
    }
    for (int i = 1; i <= n*n; i++)
    {
        if (v[i]) continue;
        v[i] = 1;
        cur[x][1] = i;
        if (check(x, 1)) dfs1(x+1, sum+i);
        v[i] = 0;
        cur[x][1] = 0;
    }
}
void init()
{
    s[1] = 1;
    for (int i = 2; i <= 200; i++)
    {
        if (!s[i])
        {
            for (int j = 2; i*j <= 200; j++) s[i*j] = 1;
        }
    }
    for (int i = 1; i <= n*n; i++)
    {
        for (int j = 1; j <= n*n; j++)
        {
            prime[i][j] = s[i+j];
        }
    }
}
int main()
{
    cin >> n;
    if (n >= 8)
    {
        if (n == 8)
        {
            cout << "1 2 3 4 7 6 5 14\n";
            cout << "12 17 20 27 34 25 18 23\n";
            cout << "11 26 21 32 39 28 61 36\n";
            cout << "8 15 46 51 58 31 48 35\n";
            cout << "9 22 57 52 55 42 41 62\n";
            cout << "10 19 40 49 54 47 56 45\n";
            cout << "13 24 43 60 53 50 33 64\n";
            cout << "16 37 30 29 44 59 38 63\n";
        }
        if (n == 9)
        {
            cout << "1 2 3 4 7 6 5 8 9\n";
            cout << "10 21 20 27 34 25 18 23 38\n";
            cout << "13 40 33 26 45 28 19 24 35\n";
            cout << "16 31 76 81 68 69 70 79 72\n";
            cout << "15 22 51 56 71 80 57 52 37\n";
            cout << "14 39 62 41 60 47 32 75 64\n";
            cout << "17 44 65 48 49 54 77 74 63\n";
            cout << "12 29 42 55 58 73 36 53 50\n";
            cout << "11 30 67 46 43 66 61 78 59\n";
        }
        if (n == 10)
        {
            cout << "1 2 3 4 7 6 5 8 9 10\n";
            cout << "12 29 38 33 34 25 36 23 44 27\n";
            cout << "11 30 59 68 45 28 43 24 35 26\n";
            cout << "18 41 42 71 56 75 64 37 66 47\n";
            cout << "13 48 19 60 53 98 93 100 91 90\n";
            cout << "16 31 40 97 54 83 74 99 82 67\n";
            cout << "15 22 49 52 55 96 77 80 57 46\n";
            cout << "14 39 58 79 72 95 62 87 70 61\n";
            cout << "17 50 51 88 85 78 89 92 81 76\n";
            cout << "20 21 32 69 94 73 84 65 86 63\n";
        }
        return 0;
    }
    init();
    cur[1][1] = 1;
    v[1] = 1;
    ans = 100000;
    dfs1(2, 0);
    if (ans == 100000) cout << "NO\n";
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << mp[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}