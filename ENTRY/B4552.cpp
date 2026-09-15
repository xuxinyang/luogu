#include <bits/stdc++.h>
using namespace std;

int main()
{
    double s = 0, x;
    for (int i = 1; i <= 12; i++)
    {
        cin >> x;
        if (x > 800) s += (x-800)*0.2;
    }
    printf("%.2lf", s);
    return 0;
}