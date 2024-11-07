#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
int t, n, a[maxn], s[maxn];
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        bool flag = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            s[i] = s[i-1] + a[i];
        }
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[n]-s[i])
            {
                flag = 1;
                cout << "Yes\n";
                break;
            }
        }
        if (!flag) cout << "No\n";
    }
    return 0;
}