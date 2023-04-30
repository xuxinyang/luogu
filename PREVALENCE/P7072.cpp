#include <bits/stdc++.h>
using namespace std;
int a[605], n, w, x;
int main()
{
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[x]++;
        int ps = 0;
        for (int j = 600; j >= 0; j--)
        {
            ps += a[j];
            if (ps >= max(1, i*w/100))
            {
                cout << j << " ";
                break;
            }
        }
    }
    return 0;
}