#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1005;
ll n, x, ans;
ll lose[maxn], win[maxn], use[maxn], f[maxn];
int main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> lose[i] >> win[i] >> use[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = x; j >= 0; j--)
        {
            if (j >= use[i]) f[j] = max(f[j] + lose[i], f[j-use[i]] + win[i]);
            else f[j] += lose[i];
        }
    }
    cout << f[x] * 5 << endl;
    return 0;
}