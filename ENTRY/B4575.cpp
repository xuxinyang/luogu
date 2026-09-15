#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a, b, t;
    cin >> a >> b >> t;
    if (a > t) 
    {
        cout << 1;
        return 0;
    }
    else if (b > t)
    {
        cout << 2;
        return 0;
    }
    for (int i = 3; ; i++)
    {
        double c = sqrt(pow(a, 2)+pow(b, 2 ));
        a = b;
        b = c;
        if (c > t) 
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}