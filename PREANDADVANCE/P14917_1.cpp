#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, max1 = 0, max2 = 0, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x == max1)
        {
            ans = max(ans, max2);
            max1 = max2 = 0;
        }
        else if (x > max1)
        {
            max2 = max1;
            max1 = x;
        }
        else if (x > max2)
        {
            max2 = x;
        }
    }
    cout << ans;
    return 0;
}