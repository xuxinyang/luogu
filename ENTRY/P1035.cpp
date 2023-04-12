#include <bits/stdc++.h>
using namespace std;

int main()
{
    double s = 0;
    int n = 0, k;
    cin >> k;
    while (s <= k)
    {
        n++;
        s += 1.0 / n;   // 浮点数和（整数或者浮点数）运算，结果才是浮点数  
    }
    cout << n << endl;
    return 0;
}