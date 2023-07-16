#include <bits/stdc++.h>
using namespace std;
int n, m, a[10], b[10], k, cnt[10];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        cnt[b[i]]++;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (cnt[i] == 2)
        {
            cout << i << endl;
            return 0;
        }
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    cout << min(a[1]*10+b[1], b[1]*10+a[1]);
    return 0;
}