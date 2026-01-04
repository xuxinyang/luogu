#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
ll n, c[N];
vector<int> ve[N];
ll dfs(int u)
{
    if (ve[u].size() == 0) return c[u];
    ll s = 0;
    for (int i = 0; i < ve[u].size(); i++)
    {
        int v = ve[u][i];
        s += dfs(v);
    }
    return min(s, c[u]);
}
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++) 
    {
        int x;
        cin >> x;
        ve[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) cin >> c[i];
    cout << dfs(1);
    return 0;
}