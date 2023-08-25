#include <bits/stdc++.h>
using namespace std;
const int maxw = 1e3+5;
int a[10], ans, w[10] = {0, 1, 2, 3, 5, 10, 20};
bool f[maxw];
int main()
{
    for (int i = 1; i <= 6; i++) cin >> a[i];
    f[0] = 1;
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= a[i]; j++)
        {
            for (int k = 1000; k >= 0; k--)
            {
                if (f[k]) f[k+w[i]] = 1;
            }
        }
    }
    for (int i = 1; i <= 1000; i++) ans += f[i];
    cout << "Total=" << ans;
    return 0;
}