#include <bits/stdc++.h>
using namespace std;
int t, n, m;
char c[105][105];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> c[i][j];
            }
        }
        bool flag = 0;
        for (int i = 1; i <= n-3; i++)
        {
            for (int j = 1; j <= m-3; j++)
            {
                if (c[i][j] == '0' && c[i][j+1] == '0' && c[i][j+2]=='0' && c[i][j+3]=='0'
                && c[i+1][j] == '0' && c[i+1][j+1] == '1' && c[i+1][j+2]=='1' && c[i+1][j+3]=='0'
                && c[i+2][j] == '0' && c[i+2][j+1] == '1' && c[i+2][j+2]=='1' && c[i+2][j+3]=='0'
                && c[i+3][j] == '0' && c[i+3][j+1] == '0' && c[i+3][j+2]=='0' && c[i+3][j+3]=='0'
                )
                {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}