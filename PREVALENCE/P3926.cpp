#include <cstdio>
#include <iostream>
using namespace std;
long long a, c, p, q, r, x;
int main()
{
    bool flag = false;
    cin >> a >> c >> p >> q >> r >> x;
    while (x > 0)
    {
        if (a < c)
        {
            if (x - p < 0)
                break;
            x = x - p;
            a++;
            flag = false;
        }
        else if (a == c && flag == false)
        {
            if (x - q < 0)
                break;
            x = x - q;
            flag = true;
        }
        else
        {
            if (x - r < 0)
                break;
            x = x - r;
            a++;
        }
    }
    cout << a << endl;
    return 0;
}