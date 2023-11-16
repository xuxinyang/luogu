#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    double sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        sum1 += x;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        sum2 += x;
    }
    cout << fixed << setprecision(6) << (sum1*3-sum2*2)/(sum1-sum2);
    return 0;
}