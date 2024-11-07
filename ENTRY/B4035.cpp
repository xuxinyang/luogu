#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (a%9==0 && a%8!=0) ans++;
    }
    cout << ans;
    return 0;
}