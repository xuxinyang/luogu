#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f[65] = {0, 1};
ll n, a, b, x, y;
void calc()
{
    while (f[y] >= b) y--;
    b -= f[y];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 2; i <= 60; i++) f[i] = f[i-1] + f[i-2];
    while (n--)
    {
        cin >> a >> b;
        x = 60, y = 60;
        while (a != b) 
        {
            if (a > b) swap(a, b), swap(x, y);
            calc();
        }
        cout << a << "\n";
    }
    return 0;
}