#include <bits/stdc++.h>
using namespace std;
double x;
int n;
double f(int n, double x)
{
    if (n == 1) return sqrt(1 + x);
    else return sqrt(n + f(n-1, x));
}
int main()
{
    cin >> x >> n;
    cout << fixed << setprecision(2) << f(n, x);
    return 0;
}