#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e4+5;
int n, x, cnt[35], ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int p = 0;
        cin >> x;
        while (x)
        {
            cnt[++p] += (x&1);
            x >>= 1;
        }
    }
    for (int i = 0; i < 32; i++)
    {
        if (cnt[i] == n) ans++;
    }
    cout << ans;
    return 0;
}