#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
double x, n, ans;
int main()
{
    cin >> x >> n;
    for (int i = 1; i <= n && pow(x,i)/i > eps; i++)
    {
        ans += pow(x,i)/i;
    }
    cout << fixed << setprecision(4) << ans;
    return 0;
}