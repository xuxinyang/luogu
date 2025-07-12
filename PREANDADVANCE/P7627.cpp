#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+5;
int a[N];
ll ans;
int main()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int bit = 0; bit <= 31; bit++)
    {
        ll cnt0 = 0, cnt1 = 0;
        for (int i = 1; i <= n; i++)
        {
            if ((a[i]>>bit)&1) cnt1++;
            else cnt0++;
        }
        ans += cnt0*cnt1*(1ll<<bit);
    }
    cout << ans;
    return 0;
}