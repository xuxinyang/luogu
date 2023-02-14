#include <bits/stdc++.h>
using namespace std;
double x, a, b, y;
int main()
{
    cin >> x >> a >> y >> b;
    cout << fixed << setprecision(2) << (x*a-y*b)/(a-b);
    return 0;
}