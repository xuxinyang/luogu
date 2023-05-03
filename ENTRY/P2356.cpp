#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
int n, ans, a[maxn][maxn], sumx[maxn], sumy[maxn], cnt;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 0) cnt++;
            sum += a[i][j];
        }
        sumx[i] = sum;
    }
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            sum += a[j][i];
        }
        sumy[i] = sum;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 0)
            {
                ans = max(ans, sumx[i]+sumy[j]);
            }
        }
    }
    if (cnt == 0) cout << "Bad\n";
    else cout << ans << "\n";
    return 0;
}