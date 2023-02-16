#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 5e5+5;
ll n, a[maxn], b[maxn], ans;

void merge_sort(int l, int r)
{
    if (l >= r) return;
    int mid = (r + l) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
        if (a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++], ans += mid - i + 1;
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (i = l; i <= r; i++) a[i] = b[i];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    merge_sort(1, n);
    cout << ans << endl;
    return 0;
}