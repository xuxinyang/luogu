#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int f = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return f * x;
}
string s;
int b[5][5][5], dp[210][210][5], p[130], d[5], len, fl;
int main()
{
    p['W'] = 1, p['I'] = 2, p['N'] = 3, p['G'] = 4;
    for (register int i = 1; i <= 4; i++)
        d[i] = read();
    for (register int i = 1; i <= 4; i++)
    {
        for (register int j = 1; j <= d[i]; j++)
        {
            cin >> s;
            b[p[s[0]]][p[s[1]]][i] = 1;
        }
    }
    cin >> s;
    len = s.size();
    for (register int i = 0; i < len; i++) dp[i][i][p[s[i]]] = 1;
    for (register int i = len - 1; i >= 0; i--)
    {
        for (register int j = i + 1; j < len; j++)
        {
            for (register int k = 1; k < 5; k++)
            {
                for (register int l = 1; l < 5 && dp[i][j][k] == 0; l++) 
                {
                    for (register int o = 1; o < 5 && dp[i][j][k] == 0; o++)
                    {
                        if (b[l][o][k] == 0) continue;
                        for (register int w = i; w < j && dp[i][j][k] == 0; w++)
                            dp[i][j][k] |= (dp[i][w][l] & dp[w + 1][j][o]);
                    }
                }
            }
        }
    }
    if (dp[0][len - 1][1]) {cout << 'W'; fl = 1;}
    if (dp[0][len - 1][2]) {cout << 'I'; fl = 1;}
    if (dp[0][len - 1][3]) {cout << 'N'; fl = 1;}
    if (dp[0][len - 1][4]) {cout << 'G', fl = 1;}
    if (fl == 0) cout << "The name is wrong!";
    return 0;
}