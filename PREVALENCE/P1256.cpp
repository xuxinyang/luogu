#include <bits/stdc++.h>
using namespace std;
int n, m, lu[200][200], ru[200][200], ld[200][200], rd[200][200];
char c[200][200];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
        }
    }
    memset(lu, 0x3f, sizeof(lu));
    memset(ru, 0x3f, sizeof(ru));
    memset(ld, 0x3f, sizeof(ld));
    memset(rd, 0x3f, sizeof(rd));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (c[i][j] == '1') lu[i][j] = 0;
            else lu[i][j] = min(lu[i-1][j], lu[i][j-1]) + 1; 
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (c[i][j] == '1') ru[i][j] = 0;
            else ru[i][j] = min(ru[i-1][j], ru[i][j+1]) + 1; 
        }
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= m; j++)
        {
            if (c[i][j] == '1') ld[i][j] = 0;
            else ld[i][j] = min(ld[i+1][j], ld[i][j-1]) + 1; 
        }
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            if (c[i][j] == '1') rd[i][j] = 0;
            else rd[i][j] = min(rd[i+1][j], rd[i][j+1]) + 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << min(min(lu[i][j], ru[i][j]), min(ld[i][j], rd[i][j])) << " ";
        }
        cout << endl;
    }
    return 0;
}