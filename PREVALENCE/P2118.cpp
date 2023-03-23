#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y)
{
    return __gcd(x, y);
}
int main()
{
    int a, b, l, ansa, ansb;
    cin >> a >> b >> l;
    ansa = l, ansb = 1;
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            if (gcd(i, j) == 1 && i * b >= j * a && i * ansb < j * ansa)
            {
                ansa = i, ansb = j;
            }
        }
    }
    cout << ansa << " " << ansb << endl;
    return 0;
}