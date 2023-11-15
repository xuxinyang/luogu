#include <bits/stdc++.h>
using namespace std;
bool flag[45];
int ans, x;
int main()
{
    for (int i = 1; i <= 10; i++)
    {
        cin >> x;
        flag[x%42] = 1;
    }
    for (int i = 0; i < 42; i++)
        if (flag[i]) ans++;
    cout << ans;
    return 0;
}