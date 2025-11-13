#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n, a[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    int p = unique(a+1, a+n+1) - a - 1;
    int c = 1, ans = 1;
    for (int i = 2; i <= p; i++)
    {
        // cout << a[i] << " ";
        if (a[i] == a[i-1]+1) c++;
        else c = 1;
        ans = max(ans, c);
    }
    cout << ans;
    return 0;
}