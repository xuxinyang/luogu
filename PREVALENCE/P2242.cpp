#include <bits/stdc++.h>
using namespace std;
int n, m, a[15005], diff[15005];
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) diff[i] = a[i] - a[i-1];
    sort(diff + 2, diff + n + 1, cmp);
    int sum = a[n] - a[1] + 1;
    for (int i = 2; i <= m; i++)
    {
        sum = sum - diff[i] + 1;
    } 
    cout << sum << endl;
    return 0;
}