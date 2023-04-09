#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
#define ll long long
int n;
ll ans;
struct Cow
{
    int x, v;
};
bool cmp(Cow x, Cow y)
{
    return x.v < y.v;
}
Cow cows[maxn], tmp[maxn];
void mergeSort(int l, int r)
{
    if (l >= r) return ;
    int mid = (l + r) >> 1;
    int i = l, k = l;
    ll sum1 = 0, sum2 = 0;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    for (i = l; i <= mid; i++) sum1 += cows[i].x;
    for (i = mid + 1; i <= r; i++)
    {
        while (k <= mid && cows[k].x < cows[i].x)
        {
            sum2 += cows[k].x;
            sum1 -= cows[k].x;
            k++;
        }
        ans += (1ll * cows[i].x * (k-l) - sum2 - 1ll * cows[i].x * (mid-k+1) + sum1) * cows[i].v;
    }
    i = l, k = l - 1;
    int j = mid + 1;
    while (i <= mid || j <= r)
    {
        if ((cows[i].x > cows[j].x || i > mid) && j <= r)
        {
            tmp[++k] = cows[j];
            j++;
        }
        else
        {
            tmp[++k] = cows[i];
            i++;
        }
    }
    for (i = 1; i <= r; i++) cows[i] = tmp[i];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> cows[i].v >> cows[i].x;
    sort(cows + 1, cows + n + 1, cmp);
    mergeSort(1, n);
    cout << ans << endl;
    return 0;
}