#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 105;
const int mod = 1e9+7;
ll n, k;
struct Matrix {
    ll mat[105][105];
};
Matrix A, B;
Matrix operator * (const Matrix &x, const Matrix &y)
{
    Matrix ans;
    memset(ans.mat, 0, sizeof(ans.mat));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                ans.mat[i][j] += x.mat[i][k] * y.mat[k][j] % mod;
                ans.mat[i][j] %= mod;
            }
        }
    }
    return ans;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> A.mat[i][j];
    // 先构造一个单位矩阵
    for (int i = 1; i <= n; i++) B.mat[i][i] = 1;
    while (k)
    {
        if (k & 1) B = B * A;
        A = A * A;
        k >>= 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << B.mat[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}