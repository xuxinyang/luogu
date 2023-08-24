#include <bits/stdc++.h>
using namespace std;
const int maxh = 5e3+5;
const int maxc = 5e4+5;
int c, h, v[maxh], f[maxc];
int main()
{
    cin >> c >> h;
    for (int i = 1; i <= h; i++) cin >> v[i];
    for (int i = 1; i <= h; i++)
    {
        for (int j = c; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j-v[i]]+v[i]);
        }
    }
    cout << f[c];
    return 0;
}