#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxa = 1e5 + 5;
int n, a[maxn], cnt[maxa][2], odd[maxa], even[maxa], ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i+=2) odd[a[i]]++;
    for (int i = 2; i <= n; i+=2) even[a[i]]++; 
    for (int i = 1; i < maxn; i++) cnt[i][0] = max(cnt[i-1][0], even[i]);
    for (int i = maxn-2; i >= 1; i--) cnt[i][1] = max(cnt[i+1][1], even[i]);
    for (int i = 1; i < maxn; i++)
    {
        if (odd[i]) ans = max(ans, odd[i]+max(cnt[i-1][0], cnt[i+1][1]));
    }
    cout << n-ans;
    return 0;
}