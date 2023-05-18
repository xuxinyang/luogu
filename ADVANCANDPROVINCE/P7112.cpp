#include <bits/stdc++.h>
#define lld long long
using namespace std;
int mod;
int solve(vector<vector<int>> mat)
{
    int n = mat.size();
    int i, j, k;
    int d, w = 1;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            while (mat[i][i])
            {
                d = mat[j][i] / mat[i][i];
                for (k = i; k <= n; ++k)
                    mat[j][k] = ((mat[j][k] - (lld)d * mat[i][k] % mod) % mod + mod) % mod;
                swap(mat[i], mat[j]);
                w = -w;
            }
            swap(mat[i], mat[j]);
            w = -w;
        }
    }
    int ret = w;
    for (i = 0; i < n; ++i)
        ret = (lld)ret * mat[i][i] % mod;
    return (ret + mod) % mod;
}
int main()
{
    vector<vector<int>> mat;
    int n;
    scanf("%d%d", &n, &mod);
    mat.resize(n);
    int i, j;
    lld k;
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
        {
            scanf("%lld", &k);
            k %= mod;
            mat[i].push_back(k);
        }
    printf("%d\n", solve(mat));
}