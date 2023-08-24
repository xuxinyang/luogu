#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
#define ll long long
ll t, n;
struct Matrix
{
    ll mat[5][5];
};
Matrix operator * (const Matrix &x, const Matrix &y)
{
    Matrix ans;
    memset(ans.mat, 0, sizeof(ans.mat));
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            for (int k = 1; k <= 3; k++)
            {
                ans.mat[i][j] += x.mat[i][k] * y.mat[k][j] % mod;
                ans.mat[i][j] %= mod;
            }
        }
    }
    return ans;
}
Matrix ans, base;
void qpow(ll b)
{
    while (b)
    {
        if (b & 1) ans = ans * base;
        base = base * base;
        b >>= 1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(ans.mat, 0, sizeof(ans.mat));
        memset(base.mat, 0, sizeof(base.mat));
        if (n <= 3) {cout << 1 << "\n"; continue;}
        ans.mat[1][1] = ans.mat[1][2] = ans.mat[1][3] = 1;
        base.mat[1][1] = base.mat[3][1] = base.mat[1][2] = base.mat[2][3] = 1;  
        qpow(n-3);
        cout << ans.mat[1][1] % mod << "\n"; 
    }
    return 0;
}