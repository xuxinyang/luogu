#include <bits/stdc++.h>
using namespace std;
int d, n, mp[130][130];
unordered_map<int, int> ump;
int main()
{
    cin >> d >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y, k;
        cin >> x >> y >> k;
        mp[x][y] = k;
    }
    int maxx = 0, cnt = 0;
    for (int i = 0; i <= 128; i++)
    {
        for (int j = 0; j <= 128; j++)
        {
            int ans = 0;
            for (int p = max(i-d,0); p <= min(128, i+d); p++)
            {
                for (int q = max(j-d,0); q <= min(128, j+d); q++)
                {
                    ans += mp[p][q];
                }
            }
            if (ump.count(ans) == 0) ump[ans]=1;
            else ump[ans]++;
        }
    }
    for (auto iter = ump.begin(); iter != ump.end(); iter++)
    {
        if (maxx < iter->first) maxx = iter->first, cnt = iter->second;
    }
    cout << cnt << " " << maxx;
    return 0;
}