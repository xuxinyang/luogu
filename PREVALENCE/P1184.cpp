#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
string space;
map<string, int> mp;
int main()
{
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    cin >> n >> m;
    getline(cin, space);
    for (int i = 1; i <= n; i++)
    {
        getline(cin, space);
        mp[space] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        getline(cin, space);
        if (!mp.count(space)) continue;
        else mp[space]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        // cout << it->first << " " << it->second << "\n";
        ans += it->second;
    }
    cout << ans << endl;
    return 0;
}