#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Coor
{
    ll x, y;
};
Coor coors[505];
ll n, k, ans, f[505][105];
ll dist(Coor A, Coor B)
{
    return abs(A.x-B.x) + abs(A.y-B.y);
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> coors[i].x >> coors[i].y;
    }
    sort(coors + 1, coors + n + 1, [](Coor A, Coor B){
        return A.x == B.x ? A.y < B.y : A.x < B.x;
    });
    for (int i = 1; i <= n; i++)
    {
        f[i][k] = 1;
        for (int j = 0; j <= k; j++)
        {
            for (int t = 1; t < i; t++)
            {
                if (coors[t].x > coors[i].x || coors[t].y > coors[i].y) continue;
                ll d = dist(coors[t], coors[i]) - 1;
                if (j + d > k) continue;
                f[i][j] = max(f[i][j], f[t][j+d] + d + 1);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            ans = max(ans, j + f[i][j]);
        }
    }
    cout << ans;
    return 0;
}