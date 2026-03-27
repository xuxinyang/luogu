#include <bits/stdc++.h>
using namespace std;
bool check(int x)
{
    while (x%2==0) x /= 2;
    while (x%5==0) x /= 5;
    return x == 1;
}
int main()
{
    int l, r, cnt=0;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        if (check(i)) cnt++;
    }
    cout << cnt;
    return 0;
}