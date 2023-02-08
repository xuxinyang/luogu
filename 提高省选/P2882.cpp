#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int n, k, a[maxn], f[maxn<<1], tag, op, ans = maxn;
int ansk, sum;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char s;
        cin >> s;
        if (s == 'B') a[i] = 0;
        if (s == 'F') a[i] = 1;
    }
    for (int k = 1; k <= n; k++)
    {
        sum = 0, tag = 0, op = 0;
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++)
        {
            if ((a[i] + tag) % 2 == 0)
            {
                if (i + k - 1 > n)
                {
                    op = 1;
                    break;
                }
                ++sum, ++tag, f[i+k-1] = -1;
            }
            if (f[i] == -1)
            {
                --tag, f[i] = 0;
            }
        }
        if (op) continue;
        if (sum < ans) ans = sum, ansk = k;
    }
    cout << ansk << " " << ans << endl;
    return 0;
}