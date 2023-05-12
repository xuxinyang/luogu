#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+5;
int n, a[maxn];
ll maxx, minx, ans1, ans2;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        int c = a[i] - a[i-1];
        if (c > 0) maxx += c;
        else minx -= c;
    }
    cout << max(maxx, minx) << "\n";
    cout << abs(maxx-minx) + 1;
    return 0;
}