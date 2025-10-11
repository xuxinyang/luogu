#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x, y, n, p, d1, d2;
    cin >> x >> y >> n >> p;
    d1 = p;
    if (p >= x) d1 -= y;
    d2 = p*n/10;
    printf("%.2lf", min(d1, d2));
    return 0;
}