#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, a = 0, ans=0, p;
    cin >> k;
    p = (int)pow(2, int(ceil(log(k)/log(2))));
    cout << p << " ";
    if (k == p) 
    {
        cout << 0 << endl;
        return 0;
    }
    while (k)
    {
        if ((k & 1) && !a) a = 1;
        if (a) ans++;
        k >>= 1;
    }
    cout << ans;
    return 0;
}