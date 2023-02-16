#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, a[maxn], b[maxn], d[maxn], f[maxn];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        f[i] = INT_MAX;
    }
    int len = 0;
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = 0, r = len, mid;
        if (d[b[i]] > f[len]) f[++len] = d[b[i]];
        else
        {
            while (l < r)
            {
                mid = (l+r)/2;
                if (f[mid] > d[b[i]]) r = mid;
                else l = mid + 1;
            }
            f[l] = min(d[b[i]], f[l]);
        }
    }
    cout << len << endl;
    return 0;
}