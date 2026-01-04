#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n, a[N];
bool check(int x)
{
    int last = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= x) continue;
        if (last && a[i]==last)
        {
            last = 0;
            continue;
        }
        else if (last && a[i] > x) return 0;
        last = a[i];
    }
    return 1;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = 1e5, ans;
    ans = r;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}