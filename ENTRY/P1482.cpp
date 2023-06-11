#include <bits/stdc++.h>
using namespace std;
int a1, b1, a2, b2, a3, b3;
int gcd(int x, int y)
{
    return __gcd(x, y);
}
int main()
{
    scanf("%d/%d", &a1, &b1);
    scanf("%d/%d", &a2, &b2);
    a3 = a1 * a2;
    b3 = b1 * b2;
    int fz = a3 / gcd(a3, b3);
    int fm = b3 / gcd(a3, b3);
    cout << fm << " " << fz << endl;
    return 0;
}