#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4+5;
int n, q;
int a[maxn], st[maxn][16];
map<int, int> mp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        mp.clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            st[i][0] = n+1;
            st[mp[a[i]]][0] = i;
            mp[a[i]] = i;
        }
        int j = 1, flag = 1;
        while (flag)
        {
            flag = 0;
            st[n+1][j-1] = n + 1;
            for (int i = 1; i <= n; i++)
            {
                if (st[i][j-1] == n+1) st[i][j] = n+1;
                else st[i][j] = st[st[i][j-1]+1][j-1];
                flag += (st[i][j]!=n+1);
            }
            j++;
        }
        cin >> q;
        while (q--)
        {
            int l, r, sum = 0;
            cin >> l >> r;
            while (l <= r)
            {
                int idx = lower_bound(st[l], st[l]+j, r+1)-st[l];
                if (idx == 0) sum++, l++;
                else l = st[l][idx-1]+1;
            }
            cout << sum << "\n";
        }
    }
    return 0;
}