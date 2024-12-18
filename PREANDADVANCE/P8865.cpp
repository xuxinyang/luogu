#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e3+5;
const int mod = 998244353;
ll ansc, ansf, C, F;
int n, m, id, t, f[maxn][maxn];
char mp[maxn][maxn];
int main()
{
    cin >> t >> id;
    while (t--)
    {
        ansc = ansf = 0;
        memset(f, 0, sizeof(f));
        cin >> n >> m >> C >> F;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++) cin >> mp[i][j];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = m-1; j >= 1; j--)
            {
                if (mp[i][j] == '1') f[i][j] = -1;
                else if (mp[i][j+1] == '0') f[i][j] = f[i][j+1]+1;
            }
        }
        for (int j = 1; j < m; j++)
        {
            int cnt1 = 0, cnt2 = 0;
            for (int i = 1; i <= n; i++)
            {
                if (f[i][j] == -1)
                {
                    cnt1 = cnt2 = 0;
                    continue;
                }
                ansc = (ansc + (1ll*f[i][j]*(cnt1%mod)) % mod) % mod;
                ansf = (ansf + cnt2) % mod;
                cnt2 = (cnt2 + (1ll*f[i][j] * (cnt1 % mod)) % mod) % mod;
                cnt1 = (cnt1 + max(0, f[i-1][j])) % mod;
            }
        }
        cout << (C*ansc) % mod << " " << (F*ansf)%mod << "\n";
    }
    return 0;
}