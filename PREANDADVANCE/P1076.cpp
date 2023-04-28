#include <bits/stdc++.h>
using namespace std;
const int mod = 20123;
const int maxn = 1e4+5;
const int maxm = 1e2+5;
int n, m, x, a[maxn][maxm], s, ans;
vector<int> v[maxn];
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> x >> a[i][j];
            if (x) v[i].push_back(j);
        }
    cin >> s;
    int tmp, idx;
    for (int i = 0; i < n; ++i)
    {
        tmp = a[i][s];
        ans = (ans + tmp) % mod;
        for (idx = 0; idx < v[i].size(); idx++)
            if (v[i][idx] >= s) break;
        s = v[i][(idx+tmp-1) % v[i].size()];
    }
    cout << ans << endl;
    return 0;
}