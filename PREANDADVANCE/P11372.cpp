#include <bits/stdc++.h>>
using namespace std;
const int maxn = 1e3 + 5;
int n, m, x, y, k;
struct Pos
{
    int p[4];
};
Pos a[maxn], b[maxn], c[maxn];
int t[maxn][maxn];
unordered_map<int, vector<int>> ud, lr, fb;
int main()
{
    cin >> n >> k;
    cin >> m >> x >> y;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= k; j++)
            cin >> a[i].p[j];
    }
    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= k; j++)
            cin >> b[i].p[j];
    }
    for (int i = 1; i <= y; i++)
    {
        for (int j = 1; j <= k; j++)
            cin >> c[i].p[j];
    }
    for (int i = 1; i <= m; i++)
    {
        int xy = a[i].p[1]*1000+a[i].p[2];
        int yz = a[i].p[2]*1000+a[i].p[3];
        int xz = a[i].p[1]*1000+a[i].p[3];
        if (ud.count(xy) == 0) ud[xy] = vector<int>(maxn);
        ud[xy][a[i].p[3]] = 1;
        if (lr.count(yz) == 0) lr[yz] = vector<int>(maxn);
        lr[yz][a[i].p[1]] = 1;
        if (fb.count(xz) == 0) fb[xz] = vector<int>(maxn);
        fb[xz][a[i].p[2]] = 1;
    }
    for (int i = 1; i <= x; i++)
    {
        int xy = b[i].p[1]*1000+b[i].p[2];
        int yz = b[i].p[2]*1000+b[i].p[3];
        int xz = b[i].p[1]*1000+b[i].p[3];
        if (ud.count(xy) == 0) ud[xy] = vector<int>(maxn);
        ud[xy][b[i].p[3]] = 2;
        if (lr.count(yz) == 0) lr[yz] = vector<int>(maxn);
        lr[yz][b[i].p[1]] = 2;
        if (fb.count(xz) == 0) fb[xz] = vector<int>(maxn);
        fb[xz][b[i].p[2]] = 2;
    }
    for (int i = 1; i <= y; i++)
    {
        int xy = c[i].p[1]*1000+c[i].p[2];
        int yz = c[i].p[2]*1000+c[i].p[3];
        int xz = c[i].p[1]*1000+c[i].p[3];
        if (ud.count(xy) == 0) ud[xy] = vector<int>(maxn);
        ud[xy][c[i].p[3]] = 2;
        if (lr.count(yz) == 0) lr[yz] = vector<int>(maxn);
        lr[yz][c[i].p[1]] = 2;
        if (fb.count(xz) == 0) fb[xz] = vector<int>(maxn);
        fb[xz][c[i].p[2]] = 2;
    }
    for (int i = 1; i <= y; i++)
    {
        int ans = 0;
        // ud
        int xy = c[i].p[1]*1000+c[i].p[2];
        if (ud.count(xy) != 0)
        {
            int u = c[i].p[3]-1, d = c[i].p[3]+1;
            while (u >= 1 && ud[xy][u] != 2 && ud[xy][u] != 3)
            {
                if (ud[xy][u] == 1) {ans++; break;}
                u--;
            }
            while (d <= n && ud[xy][d] != 2 && ud[xy][d] != 3)
            {
                if (ud[xy][d] == 1) {ans++; break;}
                d++;
            }
        }
        // lr
        int yz = c[i].p[2]*1000+c[i].p[3];
        if (lr.count(yz) != 0)
        {
            int l = c[i].p[1]-1, r = c[i].p[1]+1;
            while (l >= 1 && lr[yz][l] != 2 && lr[yz][l] != 3)
            {
                if (lr[yz][l] == 1) {ans++; break;}
                l--;
            }
            while (r <= n && lr[yz][r] != 2 && lr[yz][r] != 3)
            {
                if (lr[yz][r] == 1) {ans++; break;}
                r++;
            }
        }
        // fb
        int xz = c[i].p[1]*1000+c[i].p[3];
        if (fb.count(xz) != 0)
        {
            int f = c[i].p[2]-1, b = c[i].p[2]+1;
            while (f >= 1 && fb[xz][f] != 2 && fb[xz][f] != 3)
            {
                if (fb[xz][f] == 1) {ans++; break;}
                f--;
            }
            while (b <= n && fb[xz][b] != 2 && fb[xz][b] != 3)
            {
                if (fb[xz][b] == 1) {ans++; break;}
                b++;
            }
        }
        cout << ans << " ";
    }
    return 0;
}
