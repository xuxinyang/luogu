#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int t, x;
bool isPrime[maxn];
void init()
{
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i < maxn; i++)
    {
        if (isPrime[i])
            for (int j = i*2; j < maxn; j += i)
                isPrime[j] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    cin >> t;
    while (t--)
    {
        cin >> x;
        int ans = 0, p = 0, flag = 0;
        while (x >= 0)
        {
            if (x == 0)
            {
                flag = 1;
                break;
            }
            if (isPrime[x])
            {
                flag = 1; 
                ans++;
                break;
            }
            x -= (1<<p);
            p++;
            ans++;
        }
        if (flag) cout << ans << "\n";
        else cout << "-1\n";
    }
    return 0;
}