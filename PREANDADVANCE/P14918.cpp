#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
ll n, ans;
vector<int> ve[N];
bool vis[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        for (int j = 2; j*j <= x; j++)
        {
            if (x%j == 0)
            {
                int cnt = 0;
                while (x % j == 0)
                {
                    cnt++;
                    x /= j;
                }
                ve[j].push_back(cnt);
            }
        }
        if (x > 1) ve[x].push_back(1);
    }
    for (int i = 1; i <= 1e5; i++)
    {
        if (ve[i].size() == 0) continue;
        sort(ve[i].begin(), ve[i].end());
        int cnt = n-ve[i].size(); 
        int p;
        if (n / 2 < cnt) p = 0;
        else p = ve[i][n/2-cnt];
        for (auto v : ve[i]) ans += abs(p-v);
        ans += (n-ve[i].size())*p;
    }
    cout << ans;
    return 0;
}