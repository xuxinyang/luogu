#include <bits/stdc++.h>
using namespace std;
const int maxm = 1e3+5;
int m, n, k, W, V, P;
vector<int> w[105];
vector<int> v[105];
int dp[maxm];
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> W >> V >> P;
        w[P].push_back(W);
        v[P].push_back(V);
        k = max(k, P);
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = m; j > 0; j--)
        {
            for (size_t k = 0; k < w[i].size(); ++k)
            {
                if (j >= w[i][k])
                {
                    dp[j] = max(dp[j], dp[j-w[i][k]] + v[i][k]);
                }
            }
        }
    }
    cout << dp[m];
    return 0;
}