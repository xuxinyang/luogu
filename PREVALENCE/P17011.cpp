#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e3+5;
int n, a[N], maxx;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if (__gcd(a[i], a[j])==1)
            {
                maxx = max(maxx, a[i]+a[j]);
            }
        }
    }
    cout << maxx;
    return 0;
}