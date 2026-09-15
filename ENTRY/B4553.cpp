#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, r, cnt = 0;
    cin >> l >> r;
    for (int i = int(sqrt(l)); i*i <= r; i++)
    {
        if (i*i >= l && i*i <= r) cnt++;
    }
    cout << cnt;
    return 0;
}