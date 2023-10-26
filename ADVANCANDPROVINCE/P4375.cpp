#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, a[maxn], ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n - 1; i++)
    {
        bool flag = true;
        for (int j = 1; j <= n-i; j++)
        {
            if (a[j] > a[j+1]) 
            {
                swap(a[j], a[j+1]);
                flag = 0;
            }
        }
        for (int j = n-i; j >= 1; j--)
        {
            if (a[j] > a[j+1]) 
            {
                swap(a[j], a[j+1]);
                flag = 0;
            }
        }
        if (flag) break;
        else ans++;
    }
    cout << ans;
    return 0;
}