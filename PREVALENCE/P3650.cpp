#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int n, a[maxn], low = INT_MAX, high = INT_MIN, ans=INT_MAX;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        low = min(a[i], low);
        high = max(a[i], high);
    }
    for (int i = low; i <= high; i++)
    {
        int s = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j] - i > 17)
                s += (a[j] - i - 17) * (a[j] - i - 17);
            if (a[j] < i)
                s += (a[j] - i) * (a[j] - i);
        }
        ans = min(s, ans);
    }
    cout << ans;
    return 0;
}