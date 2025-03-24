#include <bits/stdc++.h>
using namespace std;
int n, m, a[505][505], cnt;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    for (int i = 1; i <= n-1; i++)
    {
        for (int j = 1; j <= m-1; j++)
        {
            if (a[i][j]*a[i+1][j+1] == a[i][j+1]*a[i+1][j]) cnt++;
        }
    }
    cout << cnt;
    return 0;
}