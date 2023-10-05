#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n, m, x, ans;
bool flag[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while (m--)
    {
        ans = 0;
        cin >> x;
        if (flag[x])
        {
            cout << 0 << " ";
            continue;
        }
        for (int i = 0; i < n; i = (i + x)%n)
        {
            if (flag[(i+x)%n] == 0)
            {
                flag[(i+x)%n] = 1;
                ans++;
            };
            if ((i + x) % n == 0) break;
        }
        cout << ans << " ";
    }

    return 0;
}