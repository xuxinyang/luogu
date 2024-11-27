#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 125e1+5;
double c[maxn][maxn];
int main()
{
    double s;
    cin >> s;
    int n = s / 2;
    for (int i = 2; i <= n; i++) 
        c[i][0] = 1, c[0][i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[i][j] = c[i-1][j]/2+c[i][j-1]/2;
        cout << fixed << setprecision(4) << c[n][n];
    return 0;
}