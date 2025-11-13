#include <bits/stdc++.h>
using namespace std;
int n, a[105], cnt;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[0] = 100;
    while (1)
    {
        int maxid = 1, minid = 0, p = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0) {p++; continue;}
            if (a[maxid] < a[i]) maxid = i;
            if (a[minid] > a[i]) minid = i;
        }
        if (p == n)
        {
            cout << cnt;
            break;
        }
        a[maxid] -= a[minid];
        cnt++;
    }
    return 0;
}