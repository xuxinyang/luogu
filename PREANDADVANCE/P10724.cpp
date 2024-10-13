#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+5;
int n, a[maxn], b[35], sum;
ll ans, cnt[1<<10];
int prime[15] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
void init()
{
    for (int i = 1; i <= 30; i++)
    {
        int j = i;
        for (int k = 1; k <= 10; k++)
        {
            while (j % prime[k] == 0)
            {
                b[i] ^= 1 << (k-1);
                j /= prime[k];
            }
        }
    }
}
int main()
{
    cin >> n;
    init();
    cnt[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum ^= b[a[i]];
        ans += cnt[sum]++;
    }
    cout << ans;
    return 0;
}