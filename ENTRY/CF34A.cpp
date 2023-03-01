#include <bits/stdc++.h>
using namespace std;
int n, a[105];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int minx = 1005;
    for (int i = 1; i < n; i++) minx = min(minx, abs(a[i]-a[i+1]));
    int id = 1;
    for (int i = 1; i < n; i++) if (abs(a[i]-a[i+1]) == minx)
    {
        id = i;
        break;
    }
    if (abs(a[n]-a[1]) < minx) id = n;
    cout << id << ' ' << (id + n) % n + 1;
    return 0;
}