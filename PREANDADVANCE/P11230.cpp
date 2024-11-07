#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n, k, q;
int li[100100];
vector<int> s[100100], ok[100100];
struct dd
{
    int r, c;
} dat[100100];
bool vis[102][200100];
int p[200100];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll i, j;
    int tp;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> q;
        memset(vis, 0, sizeof vis);
        for (i = 1; i <= n; i++)
        {
            cin >> li[i];
            s[i].clear();
            s[i].push_back(0);
            ok[i].clear();
            ok[i].resize(li[i] + 1);
            for (j = 1; j <= li[i]; j++)
            {
                cin >> tp;
                s[i].push_back(tp);
            }
        }
        for (i = 1; i <= q; i++)
        {
            cin >> dat[i].r >> dat[i].c;
        }
        for (i = 1; i <= n; i++)
            for (j = 1; j <= li[i]; j++)
                if (s[i][j] == 1)
                    ok[i][j] = 1;
                else
                    ok[i][j] = 0;
        for (i = 1; i <= 100; i++)
        {
            for (j = 1; j <= 200000; j++)
                p[j] = 0;
            for (j = 1; j <= n; j++)
            {
                int lst = -1e6;
                for (int z = 1; z <= li[j]; z++)
                {
                    if (z - lst + 1 <= k)
                    {
                        if (p[s[j][z]] == 0)
                            p[s[j][z]] = j;
                        else if (p[s[j][z]] != j)
                            p[s[j][z]] = 1e6;
                        vis[i][s[j][z]] = 1;
                    }
                    if (ok[j][z])
                        lst = z;
                }
            }
            for (j = 1; j <= n; j++)
            {
                for (int z = 1; z <= li[j]; z++)
                {
                    if (p[s[j][z]] && p[s[j][z]] != j)
                        ok[j][z] = 1;
                    else
                        ok[j][z] = 0;
                }
            }
        }
        for (i = 1; i <= q; i++)
        {
            if (vis[dat[i].r][dat[i].c])
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}