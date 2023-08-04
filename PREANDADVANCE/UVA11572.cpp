#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
map<int, int> snow;
int t, n, ans, last, a;
int main()
{
    cin >> t;
    while (t--)
    {
        snow.clear();
        cin >> n;
        last = ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            if (snow[a] > last)
                last = snow[a];
            ans = max(ans, i - last);
            snow[a] = i;
        }
        cout << ans << "\n";
    }
    return 0;
}