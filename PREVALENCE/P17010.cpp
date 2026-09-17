#include <bits/stdc++.h>
using namespace std;
int n, a[1005], s = 0;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = n; i >= 1; i--) s += a[i]*i;
    cout << s;
    return 0;
}