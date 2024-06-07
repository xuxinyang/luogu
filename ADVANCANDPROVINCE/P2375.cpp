#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
const int maxn = 1e6+5;
int n, fail[maxn], ans[maxn];
ll cnt;
char c[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, i, j;
    cin >> t;
    while (t--)
    {
        cin >> c;
        n = strlen(c);
        memset(fail, 0, sizeof(fail));
        j = 0, ans[0] = 0, ans[1] = 1;
        for (i = 1; i < n; i++)
        {
            while (j && (c[i] != c[j])) j = fail[j];
            j += (c[i] == c[j]);
            fail[i+1] = j;
            ans[i+1] = ans[j] + 1;
        }
        j = 0, cnt = 1;
        for (i = 1; i < n; i++)
        {
            while (j && (c[i] != c[j])) j = fail[j];
            j += (c[i] == c[j]);
            while ((j<<1)>(i+1)) j = fail[j];
            cnt = (cnt * (ll)(ans[j]+1)) % mod;
        }
        cout << cnt << "\n";
    }
    return 0;
}