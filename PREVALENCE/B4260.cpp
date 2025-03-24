#include <bits/stdc++.h>
using namespace std;
int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
int main()
{
    int y, m, d, h, k;
    cin >> y >> m >> d >> h >> k;
    if ((y%4 == 0 && y%100 != 0) || y%400 == 0) months[1] = 29;
    if (h+k >= 24)
    {
        d++;
        h = (h+k)%24;
        if (d > months[m-1])
        {
            d = 1;
            m++;
            if (m > 12)
            {
                m = 1;
                y++;
            }
        }
    }
    else h += k;
    cout << y << " " << m << " " << d << " " << h << endl;
    return 0;
}