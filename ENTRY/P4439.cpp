#include <bits/stdc++.h>
using namespace std;
char cur, last;
int n, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cur;
        if (cur != last) ans++;
        last = cur;
    }
    cout << ans+1;
    return 0;
}