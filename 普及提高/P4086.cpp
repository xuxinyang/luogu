#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, a[maxn], sum[maxn], mi[maxn];
int main()
{
    cin >> n;
    memset(mi, 0x3f, sizeof(mi));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for (int k = n-2; k >= 1; k--)
    {
        mi[k] = min(mi[k+1],a[k]);
    }
    double maxx = 0, minx = INT_MAX;
    for (int k = 1; k <= n-2; k++)
    {
        maxx = max((sum[n]-sum[k]-mi[k])/(double)(n-k-1),maxx);
    }
    for (int k = 1; k <= n-2; k++)
    {
        if ((sum[n]-sum[k]-mi[k])/double(n-k-1)==maxx)
            cout << k << endl;
    }
    return 0;
}