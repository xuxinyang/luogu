#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, s, cnt2, cnt5;
int main()
{
    s = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int k = i;
        while (k % 2 == 0) k /= 2, cnt2++;
        while (k % 5 == 0) k /= 5, cnt5++;
        s = s*k%10;
    }
    if (cnt2 > cnt5)
    {
        for (int i = 1; i <= cnt2-cnt5; i++) s = s*2%10;
    }
    cout << s;
    return 0;
}