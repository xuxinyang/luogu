#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
char a[maxn];
int b[maxn];
int main()
{
    int n;
    cin >> n;
    cin >> a;
    for (int j = n; j < n * 2; j++)
    {
        a[j] = a[j - n];
    }
    int mx = 0;
    for (int j = 0; j < 2 * n; j++)
    {
        int l = j, r = j + 1;
        char la = a[l];
        char ra = a[r];
        if (a[l] == 'w')
        {
            la = a[l - 1];
        }
        if (a[r] == 'w')
        {
            ra = a[r - 1];
        }
        int ans = 0;
        while (l >= 0)
        {
            if (a[l] == la || a[l] == 'w')
            {
                ans++;
            }
            else
                break;
            l--;
        }
        while (r < 2 * n)
        {
            if (a[r] == ra || a[r] == 'w')
            {
                ans++;
            }
            else
                break;
            r++;
        }
        mx = max(mx, ans);
    }
    if (mx > n)
        mx = n;
    cout << mx << endl;
    return 0;
}