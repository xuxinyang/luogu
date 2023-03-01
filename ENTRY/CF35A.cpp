#include <bits/stdc++.h>
using namespace std;
int a[4], x, b, c;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> x;
    a[x] = 1;
    for (int i = 1; i <= 3; i++)
    {
        cin >> b >> c;
        swap(a[b], a[c]);
    }
    for (int i = 1; i <= 3; i++)
    {
        if (a[i]) cout << i;
    }
    return 0;
}