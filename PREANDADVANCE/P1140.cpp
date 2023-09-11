#include <bits/stdc++.h>
using namespace std;
int lena, lenb, a[105], b[105], f[105][105];
char c;
const int tb[6][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 5,-1,-2,-1,-3},
    {0,-1, 5,-3,-2,-4},
    {0,-2,-3, 5,-2,-2},
    {0,-1,-2,-2, 5,-1},
    {0,-3,-4,-2,-1, 0}
};
unordered_map<char, int> ump = 
{
    {'A',1},
    {'C',2},
    {'G',3},
    {'T',4}
};
int main()
{
    cin >> lena;
    for (int i = 1; i <= lena; i++)
    {
        cin >> c;
        a[i] = ump[c];
    }
    cin >> lenb;
    for (int i = 1; i <= lenb; i++)
    {
        cin >> c;
        b[i] = ump[c];
    }
    for (int i = 1; i <= lena; i++)
    {
        f[i][0] = f[i-1][0] + tb[a[i]][5];
    }
    for (int i = 1; i <= lenb; i++)
    {
        f[0][i] = f[0][i-1] + tb[5][b[i]];
    }
    for (int i = 1; i <= lena; i++)
    {
        for (int j = 1; j <= lenb; j++)
        {
            f[i][j] = max(f[i-1][j-1]+tb[a[i]][b[j]], max(f[i-1][j] + tb[a[i]][5], f[i][j-1]+tb[5][b[j]]));
        }
    }
    cout << f[lena][lenb];
    return 0;
}