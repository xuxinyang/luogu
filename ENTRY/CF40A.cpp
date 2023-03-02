#include <bits/stdc++.h>
using namespace std;
int x, y, r;
int main()
{
    cin >> x >> y;
    r = sqrt(x * x + y * y);
    if ((r % 2 == 0 && x * y >= 0) 
    || (r % 2 && x * y <= 0) 
    || r * r == x * x + y * y)
        cout << "black";
    else
        cout << "white";
    return 0;
}