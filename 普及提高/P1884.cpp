#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e3+5;
ll n, x[maxn], y[maxn], x2[maxn], y2[maxn], side[maxn<<1];
int arr[maxn];
ll ans;
bool cmp(int a, int b)
{
    return y[a] > y[b];
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> x2[i] >> y2[i];
        side[2*i] = x[i];
        side[2*i+1] = x2[i];
    }
    sort(side, side + 2 * n);
    for (int i = 1; i < 2 * n; i++)
    {
        if (side[i-1] == side[i]) continue;
        int m = 0;
        for (int j = 0; j < n; j++)
        {
            if (x[j] <= side[i-1] && side[i] <= x2[j]) arr[m++] = j;
        }
        sort(arr, arr + m, cmp);
        ll h = y[arr[0]], d = y2[arr[0]], w = side[i] - side[i-1];
        for (int j = 1; j < m; j++)
        {
            int tmp = arr[j];
            if (y[tmp] > d)
            {
                ans += (h - y[tmp]) * w;
                h = y[tmp];
            }
            else
            {
                ans += (h - d) * w;
                h = y[tmp];
            }
            if (y2[tmp] < d) d = y2[tmp];
        }
        ans += (h-d) * w;
    }
    cout << ans << endl;
    return 0;
}