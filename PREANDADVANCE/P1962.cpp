#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
#define ll long long
ll n;
struct Matrix
{
    ll mat[5][5];
};
Matrix operator * (const Matrix &x, const Matrix &y)
{
    Matrix ans;
    memset(ans.mat, 0, sizeof(ans.mat));
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            for (int k = 1; k <= 2; k++)
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
    cin >> n;
    if (n <= 2) return puts("1"), 0;
    ans.mat[1][1] = ans.mat[1][2] = 1;
    base.mat[1][1] = base.mat[1][2] = base.mat[2][1] = 1;  
    qpow(n-2);
    cout << ans.mat[1][1] % mod; 
    return 0;
}