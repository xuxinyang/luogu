#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2+5;
int n, a[maxn], q;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        sort(a+l, a+r+1);
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    return 0;
}