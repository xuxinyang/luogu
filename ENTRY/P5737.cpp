#include <bits/stdc++.h>
using namespace std;

bool isleap(int x)
{
    if (x % 400 == 0 || x % 4 == 0 && x % 100 != 0)
        return true;
    else return false;
}
int a[1000], p;
int main()
{
    int x, y;
    cin >> x >> y;
    for (int i = x; i <= y; i++)
    {
        if (isleap(i)) a[++p] = i;
    }
    cout << p << "\n";
    for (int i = 1; i <= p; i++) cout << a[i] << " ";
    return 0;
}