#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int n, a[maxn][5], ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
        a[i][4] = a[i][1] + a[i][2] + a[i][3];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if (abs(a[i][4] - a[j][4]) <= 10
            && abs(a[i][1] - a[j][1]) <= 5
            && abs(a[i][2] - a[j][2]) <= 5
            && abs(a[i][3] - a[j][3]) <= 5)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}