#include <bits/stdc++.h>
using namespace std;
double dist(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}
int main()
{
    double a1, b1, a2, b2, a3, b3, ans=0;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    ans += dist(a1, b1, a2, b2);
    ans += dist(a1, b1, a3, b3);
    ans += dist(a2, b2, a3, b3);
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}